#lang racket

;; A Queue ADT in Racket

(provide create-queue queue-add queue-remove queue-front queue-empty?)

;; (create-queue) creates a new queue
;; create-queue: Void -> Queue

;; (queue-add i q) add i to the back of queue q
;; queue-add: Any Queue -> Queue

;; (queue-remove q) removes the first item from the queue q
;; requires: q is non-empty
;; queue-remove: Queue -> Queue

;; (queue-front q) produces the first item in queue q
;; requires: q is non-empty
;; front: Queue -> Any

;; (queue-empty? q) determines if queue q is empty
;; queue-empty?: Queue -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; do not modify the file above this line

;; INTEGRITY STATEMENT (modify if neccessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster  
;; login ID: R2DEMPST

;; IMPLEMENTATION BELOW

(struct queue (lst))

(define (create-queue)
  (queue empty))

(define (queue-add i q)
  (queue (reverse (cons i (reverse (queue-lst q))))))

(define (queue-remove q)
  (queue (rest (queue-lst q))))

(define (queue-front q)
  (first (queue-lst q)))

(define (queue-empty? q)
  (empty? (queue-lst q)))





