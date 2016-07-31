#lang racket

(require "../common/uw-api.rkt")

;; INTEGRITY STATEMENT (modify if neccessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster  
;; login ID: R2DEMPST

;;;;;;;;;;;;;;;;
;; INTERFACE: ;;
;;;;;;;;;;;;;;;;

;; An Interface for some user friendly functions created using 
;; data from the UW-API

(provide meal-info menu-lookup)

;;(menu-lookup outlet day meal) produces the menu for Outlet ;;'outlet' on Day 'day' for Meal 'meal'
;;menu-lookup: Outlet Day Meal -> (listof (list String String))

;;(meal-info id) produces the important Nutritional Facts about 
;;   the meal with product_id 'id'
;;meal-info: Nat -> (listof String)

;;Available Outlets (not case sensitive):
;;Mudie's
;;REVelation
;;Pastry Plus

;;Available Days (not case sensitive):
;;Monday-Friday (inclusive)

;;Available Meals (not casae sensitive):
;;Lunch
;;Dinner

;;1, (menu-lookup):
;;(menu-lookup "revelation" "thursday" "dinner") Date: Jan 14 2016
;;==>
;;'(("Meal: Chef's Feature" "Meal ID: null") 
;; ("Meal: Chef's Feature" "Meal ID: null") 
;; ("Meal: R - Hoisin Grilled Chicken on a Bed of Sesame Baby Bok" "Meal ID: 2574"))

;;2, (menu-lookup): 
;; (menu-lookup "mudie's" "friday" "Dinner") Date: Jan 14, 2016
;;==>
;;'(("Meal: Black Bean Sheppards Pie topped with Sweet Potato" "Meal ID: null") 
;;("Meal: R - Cajun Catfish" "Meal ID: 2696") ("Meal: R - Italian Deli Calzone" "Meal ID: 2478"))

;;3, (meal-info):
;;(meal-info 2574) From REVelation Jan 14 2016 dinner
;;==>
;;'("Meal Name: R - Hoisin Grilled Chicken on a Bed of Sesame Baby Bok" 
;;"Ingredients: Chicken, bok choy, olive oil, sesame oil, sugar, soy sauce, 
;;sherry wine, corn starch, white vinegar, salt, corn syrup, garlic, spices" 
;;"Calories: 300" 
;;"% Daily Fat: 29" 
;;"% Daily Saturated Fat: 18" 
;;"% Daily Trans Fat: null" 
;;"% Daily Sodium: 48" 
;;"% Daily Carbohydrates: 3" 
;;"% Daily Fibre: 4" 
;;"Sugar (grams): 5" 
;;"Protein (grams): 26" 
;;"% Daily Vitamin A: 50" 
;;"% Daily Vitamin C: 2" 
;;"% Daily Calcium: 2" 
;;"% Daily Iron: 6")



;;;;;;;;;;;;;;;;;;;;;
;; IMPLEMENTATION: ;;
;;;;;;;;;;;;;;;;;;;;;

;;===========MENU LOOKUP=========================

(define (outlet-list) (find-entry-helper 
                       (uw-api "/foodservices/menu") "outlets"))

;;(get-outlet outlet) filters the whole outlet-list down to just
;;   the outlet we want
;;get-outlet: String -> Info
(define (get-outlet outlet)
  ;;(get-outlet-cut outlet) cuts down the outlet info to just 
  ;;   the menu
  ;;get-outlet-cut: Info -> Info
  (define (get-outlet-cut outlet)
    (find-entry-helper (first outlet) "menu"))
  (get-outlet-cut (filter (lambda (x) 
                            (string=? (string-downcase 
                                       (find-entry-helper x                                                   "outlet_name")) 
                                      (string-downcase
                                       outlet))) 
                          (outlet-list))))

;;(get-day outlet day) filters the whole outlet-list down to just
;;   the outlet and day we want
;;get-day: String String -> Info
(define (get-day outlet day)
  (find-entry-helper 
   (first (filter (lambda (curr-day) 
                    (string=? (string-downcase day)
                              (string-downcase 
                               (find-entry-helper curr-day
                                                  "day")))) 
                  (get-outlet outlet))) "meals"))

;;(get-meal outlet day meal) filters the whole outlet-list
;;   down to just the outlet, day, and meal we want
;;get-meal: String String String -> Info
(define (get-meal outlet day meal)
  (second (first (filter (lambda (curr-meal) 
                           (string=? (string-downcase meal)
                                     (string-downcase 
                                      (first curr-meal))))
                         (get-day outlet day)))))

;;Description given in interface
(define (menu-lookup outlet day meal)
  (map (lambda (item)
         (newline) item) (foldr (lambda (curr-item items)
           (cons (list (string-append "Meal: " 
                                      (find-entry-helper 
                                       curr-item 
                                       "product_name")) 
                       (string-append "Meal ID: " 
                                      (my-number->string 
                                       (check-null 
                                        (find-entry-helper 
                                         curr-item 
                                         "product_id"))))) 
                 items)) empty (get-meal outlet day meal))))

;;(find-entry-helper info entry) finds the sub-list in the list 
;;'info' that has a string equivalent to 'entry' as its first 
;;element, or an error if no such entry exists
;;find-entry-helper: (listof (list String X)) -> X
(define (find-entry-helper info entry)
  (cond 
   [(empty? info) (error "Didn't find entry")]
   [(string=? (first (first info)) entry) (second (first 
                                                   info))]
   [else (find-entry-helper (rest info) entry)]))



;;=====================MEAL INFO======================

;;Description given in interface
(define (meal-info id)
  (define x (uw-api (string-append "/foodservices/products/" 
                                   (number->string id))))
  (list (string-append "Meal Name: " 
                       (check-null (find-entry-helper 
                                    x "product_name")))
  (string-append "Ingredients: " 
                 (check-null (find-entry-helper 
                              x "ingredients")))
  (string-append "Calories: " (my-number->string 
                               (check-null (find-entry-helper 
                                            x "calories"))))
 (string-append "% Daily Fat: " (my-number->string 
                                 (check-null (find-entry-helper 
                                              x                                          "total_fat_percent"))))
 (string-append "% Daily Saturated Fat: " 
                (my-number->string (check-null 
                                    (find-entry-helper 
                                                x 
                                    "fat_saturated_percent")))) 
 (string-append "% Daily Trans Fat: " 
                (my-number->string (check-null 
                                    (find-entry-helper 
                                                x 
                                     "fat_trans_percent")))) 
 (string-append "% Daily Sodium: " 
                (my-number->string (check-null 
                                    (find-entry-helper 
                                                x                                                   "sodium_percent"))))
  (string-append "% Daily Carbohydrates: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "carbo_percent"))))
  (string-append "% Daily Fibre: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "carbo_fibre_percent"))))
  (string-append "Sugar (grams): " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "carbo_sugars_g"))))
  (string-append "Protein (grams): " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "protein_g"))))
  (string-append "% Daily Vitamin A: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "vitamin_a_percent")))) 
  (string-append "% Daily Vitamin C: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "vitamin_c_percent")))) 
  (string-append "% Daily Calcium: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "calcium_percent"))))
  (string-append "% Daily Iron: " 
                 (my-number->string (check-null 
                                     (find-entry-helper 
                                                 x 
                                      "iron_percent"))))))

;;(check-null item) produces "Info not provided" if item is
;;   null, or item otherwise
;;check-null: X -> (anyof String X)
(define (check-null item)
  (cond
   [(null? item) "Info not provided"]
   [else item]))
  
;;(my-number->string item) produces the string form of item
;;   if it's a number, or item otherwise
;;my-number->string: X -> (anyof String X)
(define (my-number->string item)
  (cond
   [(number? item) (number->string item)]
   [else item]))
