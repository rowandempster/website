# CS-135-Work
1A UW

Assignment 5 Problem 3


;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 05, Problem 3
;;**********************************************

;;Given data definitions:

(define-struct pprof (title wts))
;; A position profile (PProf) is a (make-pprof Sym (listof Nat)).



;;******************************************************************************



;; part (a)

;;(applicant-score applicant pprof) produces the applicant score of "applicant"
;;   for the position "pprof"

;;applicant-score: (listof Nat) PProf -> Nat

;;requires: The number of skills the applicant has much be equivalent to the
;;   the number of skills in the PProf's wts field

;;Examples:
(check-expect (applicant-score (list 5 3 8 5)
                               (make-pprof 'designer (list 3 8 4 4))) 91)
(check-expect (applicant-score (list 2 7)
                               (make-pprof 'engineer (list 2 9))) 67)
(check-expect (applicant-score (list 8 3 5 0 3 8)
                               (make-pprof 'maker (list 1 4 3 8 2 7))) 97)

(define (applicant-score applicant pprof)
  (cond
    [(empty? applicant) 0] ;;applicant and wts are equal length, so lockstep 
    [else (+ (* (first applicant) (first (pprof-wts pprof)))
             (applicant-score (rest applicant)
                              (make-pprof (pprof-title pprof)
                                          (rest (pprof-wts pprof)))))]))

;;Tests:
(check-expect (applicant-score empty
                               (make-pprof 'designer empty)) 0)
(check-expect (applicant-score (list 0 0 0 0 1 0)
                               (make-pprof 'moper (list 0 0 0 0 8 0))) 8)
(check-expect (applicant-score (list 0 0 0 0 0 0)
                               (make-pprof 'sweeper (list 5 4 8 3 5 6))) 0)
(check-expect (applicant-score (list 6 4 6 3 1 5)
                               (make-pprof 'creator (list 0 0 0 0 0 0))) 0)
(check-expect (applicant-score (list 1 1 1 1 1 1)
                               (make-pprof 'mover (list 1 1 1 1 1 1 ))) 6)



;;******************************************************************************



;; part (b)

;;(position-max applicant pprof1 pprof2) produces the position profile (pprof1
;;   or pprof2) that has the greater applicant score for "applicant". If the
;;   applicant scores are the same, produces pprof1

;;position-max: (listof Nat) PProf PProf -> PProf

;;requires: The number of skills the applicant has much be equivalent to the
;;   the number of skills in the PProf's wts field

;;Examples:
(check-expect (position-max (list 4 3 7 6) (make-pprof 'phoner (list 4 3 8 5))
                            (make-pprof 'cooker (list 8 3 6 5)))
              (make-pprof 'cooker (list 8 3 6 5)))
(check-expect (position-max (list 6 4) (make-pprof 'walker (list 8 5))
                            (make-pprof 'runner (list 9 3)))
              (make-pprof 'walker (list 8 5)))
(check-expect (position-max (list 5 4 8 4 5)
                            (make-pprof 'walker (list 4 9 3 6 5))
                            (make-pprof 'runner (list 9 4 8 1 6)))
              (make-pprof 'runner (list 9 4 8 1 6)))

(define (position-max applicant pprof1 pprof2)
  (cond
    [(>= (applicant-score applicant pprof1) (applicant-score applicant pprof2))
     pprof1]
    [else pprof2]))

;;Tests:
(check-expect (position-max empty
                            (make-pprof 'walker empty)
                            (make-pprof 'runner (list 9 4 8 1 6)))
              (make-pprof 'walker empty))
(check-expect (position-max empty
                            (make-pprof 'walker empty)
                            (make-pprof 'runner empty))
              (make-pprof 'walker empty))
(check-expect (position-max (list 1)
                            (make-pprof 'walker (list 0))
                            (make-pprof 'runner (list 1)))
              (make-pprof 'runner (list 1)))
(check-expect (position-max (list 1 2 3 4 5)
                            (make-pprof 'walker (list 1 1 1 1 1))
                            (make-pprof 'runner (list 1 0 0 0 3)))
              (make-pprof 'runner (list 1 0 0 0 3)))
(check-expect (position-max (list 1 2 3 4 5)
                            (make-pprof 'walker (list 1 1 1 1 1))
                            (make-pprof 'runner (list 0 0 0 0 3)))
              (make-pprof 'walker (list 1 1 1 1 1)))
(check-expect (position-max (list 1 2 3 4 5)
                            (make-pprof 'walker (list 2 1 1 1 1))
                            (make-pprof 'runner (list 0 0 0 0 3)))
              (make-pprof 'walker (list 2 1 1 1 1)))



;;******************************************************************************



;; part (c)

;;(position-list-max applicant lopprof) finds the most suitable pprof for 
;;   applicant out out loppfof. If two pprof's are the most suitable the earlier 
;;   one in pprof is produced

;;position-list-max: (listof Nat) (listof PProf) -> PProf

;;requires: lopprof is non-empty

;;Examples:
(check-expect (position-list-max (list 5 8 3 6)
                                 (list (make-pprof 'designer (list 3 8 4 6))))
              (make-pprof 'designer (list 3 8 4 6)))
(check-expect (position-list-max (list 5 8 3 6)
                                 (list (make-pprof 'designer (list 3 8 4 6))
                                       (make-pprof 'walker (list 4 8 5 2))
                                       (make-pprof 'runner (list 5 8 3 6))))
              (make-pprof 'runner (list 5 8 3 6)))
(check-expect (position-list-max (list 1 8 9 6)
                                 (list (make-pprof 'designer (list 3 8 4 6))
                                       (make-pprof 'walker (list 4 8 5 2))
                                       (make-pprof 'runner (list 5 8 3 6))))
              (make-pprof 'designer (list 3 8 4 6)))

(define (position-list-max applicant lopprof)
  (cond
    [(= (length lopprof) 1) (first lopprof)]
    [(>= (applicant-score applicant (position-max applicant
                                                  (first lopprof)
                                                  (second lopprof)))
         (applicant-score applicant (position-list-max applicant
                                                       (rest lopprof))))
     (position-max applicant (first lopprof) (second lopprof))]
    [else (position-list-max applicant (rest lopprof))]))

;;Tests:
(check-expect (position-list-max (list 1 2 1 2)
                                 (list (make-pprof 'designer (list 0 1 1 1))
                                       (make-pprof 'walker (list 0 3 0 0))
                                       (make-pprof 'runner (list 1 1 1 1))))
              (make-pprof 'walker (list 0 3 0 0)))
(check-expect (position-list-max (list 1 2 1 2)
                                 (list (make-pprof 'designer (list 0 1 1 1))
                                       (make-pprof 'walker (list 0 3 0 0))
                                       (make-pprof 'runner (list 1 5 1 1))
                                       (make-pprof 'clock (list 1 6 2 3))
                                       (make-pprof 'calculator (list 3 2 1 1))))
              (make-pprof 'clock (list 1 6 2 3)))
(check-expect (position-list-max (list 1 1 1 1)
                                 (list (make-pprof 'designer (list 0 0 0 1))
                                       (make-pprof 'walker (list 1 0 0 0))
                                       (make-pprof 'runner (list 1 0 0 1))
                                       (make-pprof 'clock (list 0 1 1 0))
                                       (make-pprof 'calculator (list 0 0 1 0))))
              (make-pprof 'runner (list 1 0 0 1)))



;;******************************************************************************



;; part (d)

;;(remove-position title lopprof) produces a new listof PProf that is the same
;;   as lopprof after removing the PProf with "title" as its title field.
;;   If no PProf in lopprof has "title", then produces lopprof

;;remove-position: Sym (listof PProf) -> (listof PProf)

;;Examples:
(check-expect
 (remove-position 'designer (list
                             (make-pprof 'runner (list 0 0 0 1))
                             (make-pprof 'walker (list 1 0 0 0))
                             (make-pprof 'designer (list 1 0 0 1))
                             (make-pprof 'clock (list 0 1 1 0))
                             (make-pprof 'calculator (list 0 0 1 0))))
 (list
  (make-pprof 'runner (list 0 0 0 1))
  (make-pprof 'walker (list 1 0 0 0))
  (make-pprof 'clock (list 0 1 1 0))
  (make-pprof 'calculator (list 0 0 1 0))))
(check-expect (remove-position 'eater (list
                                       (make-pprof 'runner (list 0 0 0 1))
                                       (make-pprof 'walker (list 1 0 0 0))
                                       (make-pprof 'designer (list 1 0 0 1))
                                       (make-pprof 'clock (list 0 1 1 0))
                                       (make-pprof 'calculator (list 0 0 1 0))))
              (list
               (make-pprof 'runner (list 0 0 0 1))
               (make-pprof 'walker (list 1 0 0 0))
               (make-pprof 'designer (list 1 0 0 1))
               (make-pprof 'clock (list 0 1 1 0))
               (make-pprof 'calculator (list 0 0 1 0))))
(check-expect
 (remove-position 'calculator (list
                               (make-pprof 'runner (list 0 0 0 1))
                               (make-pprof 'walker (list 1 0 0 0))
                               (make-pprof 'designer (list 1 0 0 1))
                               (make-pprof 'clock (list 0 1 1 0))
                               (make-pprof 'calculator (list 0 0 1 0))))
 (list
  (make-pprof 'runner (list 0 0 0 1))
  (make-pprof 'walker (list 1 0 0 0))
  (make-pprof 'designer (list 1 0 0 1))
  (make-pprof 'clock (list 0 1 1 0))))

(define (remove-position title lopprof)
  (cond
    [(empty? lopprof) empty]
    [(and (= (length lopprof) 1)
          (symbol=? title (pprof-title (first lopprof)))) empty]
    [(symbol=? title (pprof-title (first lopprof)))
     (cons (second lopprof) (rest (rest lopprof)))]
    [else (cons (first lopprof) (remove-position title (rest lopprof)))]))

;;Tests:

(check-expect (remove-position 'calculator empty)
              empty)

(check-expect (remove-position 'nothing (list
                                         (make-pprof 'nothing (list 0 0 0 1))
                                         (make-pprof 'walker (list 1 0 0 0))
                                         (make-pprof 'nothing (list 1 0 0 1))
                                         (make-pprof 'nothing (list 0 1 1 0))
                                         (make-pprof 'nothing (list 0 0 1 0))))
              (list
               (make-pprof 'walker (list 1 0 0 0))
               (make-pprof 'nothing (list 1 0 0 1))
               (make-pprof 'nothing (list 0 1 1 0))
               (make-pprof 'nothing (list 0 0 1 0))))











