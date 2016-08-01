#lang racket

(require "../common/uw-api.rkt")

;; INTEGRITY STATEMENT (modify if neccessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster  
;; login ID: 20635120

;;;;;;;;;;;;;;;;
;; INTERFACE: ;;
;;;;;;;;;;;;;;;;

;; An Interface for some user friendly functions created using 
;; data from the UW-API

(provide parking-availability course-sections course-capacity)

;;(parking-availability lot) produces the number of empty spots 
;; in parking lot 'lot'
;;cur-temp: Lot -> Nat

;;(course-sections term subject catalog) produces a list of 
;;strings that correspond to all section names for the course
;;course-sections: Term Subject Catalog -> (listof String)

;;(course-capacity term subject catalog) produces a list of 
;; lists containing all lecture sections, the capacity of that
;; lecture section, and current enrollment of that lecture 
;; section
;;course-capacity: Term Subject Catalog -> 
;;                 (listof (list String Nat Nat))

;;;;;;;;;;;;;;;;;;;;;
;; IMPLEMENTATION: ;;
;;;;;;;;;;;;;;;;;;;;;

;;The data type Info (as used in the local funciton contracts 
;;below) is data retrived from the UW-API. As stated in the
;;assingment summary, "some...will be lists of lists of lists", 
;;and others just Nats.

(define (parking-availability lot)
  ;;(parking-availability-info info) does the same thing as its  
  ;;   wrapper, but with the data retrieved from the UW-API
  ;;parking-availability: Info -> Nat
  (define (parking-availability-info info)
    (cond
     [(empty? info) (error "Lot not found")]
     [(string=? (second (first (first info))) lot)
      (- (find-entry-helper (first info) "capacity")
         (find-entry-helper (first info) "current_count"))]
     [else (parking-availability-info (rest info))]))
  (parking-availability-info (uw-api "/parking/watpark")))

(define (course-sections term subject catalog)
  ;;(course-sections-info info) does the same thing as its      
  ;;   wrapper, but with the data retrieved from the UW-API
  ;;course-selections-info: Info -> (listof String)
  (define (course-sections-info info)
    (cond
     [(empty? info) empty]
     [else (cons (find-entry-helper (first info) "section")
                 (course-sections-info (rest info)))]))
  (course-sections-info (uw-api 
                         (string-append "/terms/" 
                                        (number->string term) 
                                        "/" subject "/" 
                                        (number->string
                                         catalog) 
                                        "/schedule"))))

(define (course-capacity term subject catalog)
  ;;(course-capacity-info info) does the same thing as its      
  ;;wrapper, but with the data retrieved from the UW-API
  ;;course-capacity-info: Info -> (listof (list String Nat
  ;;                                                   Nat))
  (define (course-capacity-info info)
    (cond
     [(empty? info) empty]
     [(string=? "LEC" (substring (find-entry-helper 
                                  (first info) "section") 0 3))
      (cons (list (find-entry-helper (first info) "section")   
                  (find-entry-helper (first info) "enrollment_capacity") 
                  (find-entry-helper (first info) "enrollment_total"))
            (course-capacity-info (rest info)))]
     [else empty]))
  (course-capacity-info (uw-api 
                         (string-append "/terms/" 
                                        (number->string term) 
                                        "/" subject "/" 
                                        (number->string
                                         catalog) 
                                        "/schedule"))))

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

