#lang racket

;; DO NOT MODIFY THIS FILE

(require "../common/io-test.rkt")
(require "mpq.rkt")

;; this is an I/O test client for the Mutable Priority Queue ADT

;; look at the simple.in and simple.expect for
;; a concrete example of how to use this test client

(io-test
  (list (list 'reset 0 (lambda (pq) (create-mpq)))
        (list 'add 2 (lambda (pq i p) (mpq-add! i p pq) pq))
        (list 'remove 0 (lambda (pq) (printf "~a\n" (mpq-remove! pq)) pq))
        (list 'top 0 (lambda (pq) (printf "~a\n" (mpq-top pq)) pq))
        (list 'empty? 0 (lambda (pq) (printf "~a\n" (mpq-empty? pq)) pq))
        (list 'quit -1)
        (list eof -1))
 (create-mpq))
