#lang racket

;; DO NOT MODIFY THIS FILE

(require "../common/io-test.rkt")
(require "stack.rkt")

;; this is an I/O test client for the Stack ADT
;; see the assignment for more details

;; look at the sample.in and sample.expect for
;; a concrete example of how to use this test client

(io-test
  (list (list 'reset 0 (lambda (s) (create-stack)))
        (list 'push 1 (lambda (s i) (stack-push i s)))
        (list 'pop 0 (lambda (s) (stack-pop s)))
        (list 'top 0 (lambda (s) (printf "~a\n" (stack-top s)) s))
        (list 'empty? 0 (lambda (s) (printf "~a\n" (stack-empty? s)) s))
        (list 'quit -1)
        (list eof -1))
 (create-stack))

