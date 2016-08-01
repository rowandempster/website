#lang racket

;; A Mutable Stack ADT in Racket (INTERFACE)
(provide create-mstack mstack-push! mstack-pop! mstack-top mstack-empty?)

;; (create-mstack) creates a new mutable stack
;; create-mstack: Void -> MStack

;; (mstack-push! i s) adds i to the top of mstack s
;; mstack-push!: Any MStack -> Void
;; effects: mutates s

;; (mstack-top s) produces the top item of mstack s
;; mstack-top: MStack -> Any
;; requires: s is non-empty

;; (mstack-pop! s) removes the top item from mstack s
;;   and produces the item popped
;; mstack-pop!: MStack -> Any
;; requires: s is non-empty
;; effects: mutates s

;; (mstack-empty? s) determines if mstack s is empty
;; mstack-empty?: MStack -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; INTEGRITY STATEMENT (modify if necessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name

;; Name: Rowan Dempster
;; login ID: R2DEMPST

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; ONLY CHANGE THE DEFINITIONS OF mstack-push! and mstack-pop!


;; A Mutable Stack ADT in Racket (IMPLEMENTATION)
(struct mstack (lst) #:mutable)

;; see interface for documentation

(define (create-mstack)
  (mstack empty))

(define (mstack-push! i s)
  (set-mstack-lst! s (cons i (mstack-lst s))))

(define (mstack-top s)
  (first (mstack-lst s)))
  
(define (mstack-pop! s)
  (define popping (mstack-top s))
  (set-mstack-lst! s (rest (mstack-lst s)))
  popping)

(define (mstack-empty? s)
  (empty? (mstack-lst s)))
