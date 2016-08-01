#lang racket

;; DO NOT MODIFY THIS FILE

(require "../common/io-test.rkt")
(require "mstack.rkt")

;; this is an I/O test client for the Mutable Stack ADT
;; see the assignment for more details

;; look at the sample.in and sample.expect for
;; a concrete example of how to use this test client

(io-test
  (list (list 'reset 0 (lambda (s) (create-mstack)))
        (list 'push 1 (lambda (s i) (mstack-push! i s) s))
        (list 'pop 0 (lambda (s) (printf "~a\n" (mstack-pop! s)) s))
        (list 'top 0 (lambda (s) (printf "~a\n" (mstack-top s)) s))
        (list 'empty? 0 (lambda (s) (printf "~a\n" (mstack-empty? s)) s))
        (list 'quit -1)
        (list eof -1))
 (create-mstack))
