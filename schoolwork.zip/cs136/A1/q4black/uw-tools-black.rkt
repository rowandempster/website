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

(provide cur-temp course-desc total-parking-capacity)

;;(cur-temp) produces the current temperature on the UWaterloo 
;;campus in Celsius
;;cur-temp: Void -> Int

;;(course-desc subject catalog) produces the course despriction 
;; refered to by 'subject' and 'catalog'
;;course-desc: Subject Catalog -> String

;;(total-parking-capacity) produces the total capacity of the 
;;parking lots on the UWaterloo Campus
;;total-parking-capacity: Void -> Nat

;;;;;;;;;;;;;;;;;;;;;
;; IMPLEMENTATION: ;;
;;;;;;;;;;;;;;;;;;;;;

(define (cur-temp)
  (find-entry-helper (uw-api "/weather/current") "temperature_current_c"))

(define (course-desc subject catalog)
  (find-entry-helper (uw-api 
                      (string-append "/courses/" subject "/" 
                                     (number->string catalog))) 
                     "description"))

(define (total-parking-capacity)
  (define (cap info)
    (cond
     [(empty? info) 0]
     [else (+ (find-entry-helper (first info) "capacity")
              (cap (rest info)))]))
  (cap (uw-api "/parking/watpark")))

;;(find-entry-helper info entry) finds the sub-list in the list 
;;'info' that has a string equivalent to 'entry' as its first 
;;element, or an error if no such entry exists
;;find-entry-helper: (listof (list String X)) -> X
(define (find-entry-helper info entry)
  (cond 
   [(empty? info) (error "Didn't find entry")]
   [(string=? (first (first info)) entry) (second (first info))]
   [else (find-entry-helper (rest info) entry)]))







