#lang racket

;; A Priority Queue ADT in Racket

(provide create-priorityq priorityq-add priorityq-remove 
         priorityq-top priorityq-empty?)

;; (create-priorityq) creates a new priority queue
;; create-priorityq: Void -> PriorityQ

;; (priorityq-add i pri pq) add item i with priority pri to pq
;; priorityq-add: Any Int PriorityQ -> PriorityQ

;; (priorityq-remove pq) removes the item with the largest priority in pq
;; requires: pq is non-empty
;; priorityq-remove: PriorityQ -> PriorityQ

;; (priorityq-top pq) returns the item with the largest priority in pq 
;;   if multiple items have the same largest priority, any can be returned
;; requires: pq is non-empty
;; priorityq-top: PriorityQ -> Any

;; (priorityq-empty? pq) determines if pq is empty
;; priorityq-empty?: PriorityQ -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; do not modify the file above this line

;; INTEGRITY STATEMENT (modify if neccessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster 
;; login ID: R2DEMPST

;; IMPLEMENTATION BELOW


(struct priorityq (lst))

(define (create-priorityq)
  (priorityq empty))

(define (priorityq-add i pri pq)
  (define (priorityq-add-list i pri pq-list)
  (cond
   [(empty? pq-list) (cons (list i pri) empty)]
   [(> pri (second (first pq-list))) 
     (cons (list i pri) pq-list)]
   [else (cons (first pq-list) (priorityq-add-list i pri (rest pq-list)))]))
  (priorityq (priorityq-add-list i pri (priorityq-lst pq))))
              
(define (priorityq-remove pq)
  (priorityq (rest (priorityq-lst pq))))

(define (priorityq-top pq)
  (first (first (priorityq-lst pq))))

(define (priorityq-empty? pq)
  (empty? (priorityq-lst pq)))


                                       


