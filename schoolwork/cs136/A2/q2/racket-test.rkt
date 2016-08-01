#lang racket

;; DO NOT MODIFY THIS FILE

(require "io-test.rkt")
(require "racket-translation.rkt")

;; this is an I/O test client for racket-translation
;; see the assignment for more details

;; look at the sample.in and sample.expect for
;; a concrete example of how to use this test client


(io-test
 (list (list 'polyeval 4 (lambda (s a b c x)
                           (printf "~a\n" (polyeval a b c x)) 0))
       (list 'selector 3 (lambda (s a x y)
                           (printf "~a\n" (selector a x y)) 0))
       (list 'max3 3 (lambda (s a b c)
                       (printf "~a\n" (max3 a b c)) 0))
       (list 'sumsqr1 1 (lambda (s n) (printf "~a\n" (sumsqr1 n)) 0))
       (list 'sumsqr2 1 (lambda (s n) (printf "~a\n" (sumsqr1 n)) 0))
       (list 'sumsqr3 1 (lambda (s n) (printf "~a\n" (sumsqr1 n)) 0))
       (list 'sameparity 2 (lambda (s a b)
                             (printf "~a\n" (sameparity a b)) 0))
       (list 'quit -1)
       (list eof -1))
 0)
