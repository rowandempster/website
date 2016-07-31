#lang racket

;; DO NOT MODIFY THIS FILE

;; A Stack ADT in Racket (INTERFACE)
(provide create-stack stack-push stack-pop stack-top stack-empty?)

;; (create-stack) creates a new stack
;; create-stack: Void -> Stack

;; (stack-push i s) adds i to the top of stack s
;; stack-push: Any Stack -> Stack

;; (stack-pop s) removes the top item from stack s
;; requires: s is non-empty
;; stack-pop: Stack -> Stack

;; (stack-top s) produces the top item of stack s
;; requires: s is non-empty
;; top: Stack -> Any

;; (stack-empty? s) determines if stack s is empty
;; stack-empty?: Stack -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; A Stack ADT in Racket (IMPLEMENTATION)
(struct stack (lst))

;; see interface for documentation

(define (create-stack)
  (stack empty))

(define (stack-push i s)
  (stack (cons i (stack-lst s))))

(define (stack-pop s)
  (stack (rest (stack-lst s))))

(define (stack-top s)
  (first (stack-lst s)))

(define (stack-empty? s)
  (empty? (stack-lst s)))
