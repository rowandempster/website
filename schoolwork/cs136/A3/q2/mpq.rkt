#lang racket

;; A Mutable Priority Queue ADT in Racket

(provide create-mpq mpq-add! mpq-remove! mpq-top mpq-empty?)

;; (create-mpq) creates a new mutable priority queue
;; create-mpq: Void -> MPQ

;; (mpq-add! i pri pq) add item i with priority pri to pq
;; mpq-add!: Any Int MPQ -> Void
;; effects: mutates pq

;; (mpq-remove! pq) removes the item with the largest priority in pq
;;   and returns the item removed.  
;;   If multiple items have the same largest priority, any can be removed
;; mpq-remove!: MPQ -> Any
;; requires: pq is non-empty
;; effects: mutates pq

;; (mpq-top pq) returns the item with the largest priority in pq.
;;   If multiple items have the same largest priority, any can be returned
;; mpq-top: MPQ -> Any
;; requires: pq is non-empty

;; (mpq-empty? pq) determines if pq is empty
;; mpq-empty?: MPQ -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; do not modify the file above this line

;; INTEGRITY STATEMENT (modify if necessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster
;; login ID: R2DEMPSTER

;; IMPLEMENTATION BELOW

(struct mqp (lst) #:mutable)

(define (create-mpq)
  (mqp empty))

;;see interface for description 
(define (mpq-add! i pri pq)
  (define (new-list lst i pri)
    (cond
     [(empty? lst) (cons (list i pri) empty)]
     [(> pri (second (first lst))) 
      (cons (list i pri) lst)]
     [else (cons (first lst) (new-list (rest lst) i pri))]))
  (set-mqp-lst! pq (new-list (mqp-lst pq) i pri)))

(define (mpq-remove! pq)
  (define removed (first (first (mqp-lst pq))))
  (set-mqp-lst! pq (rest (mqp-lst pq)))
  removed)

(define (mpq-top pq)
  (first (first (mqp-lst pq))))

(define (mpq-empty? pq)
  (empty? (mqp-lst pq)))




