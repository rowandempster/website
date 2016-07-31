#lang racket

;; This is an example that illustrates how to use a mutable structure in Racket

;; First, we will define a mutable posn structure (mposn)
;; For convenience we will also make the structure transparent

(struct mposn (x y) #:mutable #:transparent)

;; in addition to mposn, mposn?, mposn-x and mposn-y...
;; the above definition also defines set-mposn-x! and set-mposn-y!

;; consider a purpose/contract for set-mposn-x!

;; (set-mposn-x! mp newx) changes the x field of mp to be newx
;; set-mposn-x!: MPosn -> Void
;; effects: modifies (mutates) the structure mp

;; the bang (!) is used to indicate that there is some mutation involved

;; here is an example of how it can be used.
;; we will name our sample mposn "bob".

(define bob (mposn 3 4))

bob  ;; => (mposn 3 4)

(set-mposn-x! bob 7)

bob  ;; => (mposn 7 4)


;; We will now define a function that mutates a structure
;; passed to the function

;; (swap! mp) swaps the x and y fields of mp
;; swap!: MPosn -> Void
;; effects: modifies (mutates) the structure mp

(define (swap! mp)
  (define oldx (mposn-x mp))
  (set-mposn-x! mp (mposn-y mp))
  (set-mposn-y! mp oldx))


;; Note that the function produces nothing (Void).
;; Its purpose is to have a side effect

;; let's see it work:

(swap! bob)

bob  ;; => (mposn 4 7)

