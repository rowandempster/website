#lang racket

;; DO NOT MODIFY THIS FILE

(require "../common/io-test.rkt")
(require "priorityq.rkt")

;; this is an I/O test client for the Priority Queue ADT

;; see the assignment and Stack ADT for more details

;; look at the simple.in and simple.expect for
;; a concrete example of how to use this test client

(io-test
  (list (list 'reset 0 (lambda (pq) (create-priorityq)))
        (list 'add 2 (lambda (pq i p) (priorityq-add i p pq)))
        (list 'remove 0 (lambda (pq) (priorityq-remove pq)))
        (list 'top 0 (lambda (pq) (printf "~a\n" (priorityq-top pq)) pq))
        (list 'empty? 0 (lambda (pq) (printf "~a\n" (priorityq-empty? pq)) pq))
        (list 'quit -1)
        (list eof -1))
 (create-priorityq))
