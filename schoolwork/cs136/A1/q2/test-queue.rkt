#lang racket

;; DO NOT MODIFY THIS FILE

(require "../common/io-test.rkt")
(require "queue.rkt")

;; this is an I/O test client for the Queue ADT

;; see the assignment and Stack ADT for more details

;; look at the simple.in and simple.expect for
;; a concrete example of how to use this test client

(io-test
  (list (list 'reset 0 (lambda (q) (create-queue)))
        (list 'add 1 (lambda (q i) (queue-add i q)))
        (list 'remove 0 (lambda (q) (queue-remove q)))
        (list 'front 0 (lambda (q) (printf "~a\n" (queue-front q)) q))
        (list 'empty? 0 (lambda (q) (printf "~a\n" (queue-empty? q)) q))
        (list 'quit -1)
        (list eof -1))
 (create-queue))

