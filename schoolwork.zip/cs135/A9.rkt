;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 09, Problem 2
;;**********************************************



;;part (a)

;;(intersection list1 list2) produces a list containing the elements that list1
;;   and list2 chare, with no duplicates

;;intersection: (listof X) (listof Y) -> (anyof (listof X) (listof Y))

;;Examples:
(check-expect (intersection (list 3 4 2 1 3) (list 1 5 7 3)) (list 1 3))
(check-expect (intersection (list 3 4 4 3 2 1) (list 1 5 7 3)) (list 1 3))
(check-expect (intersection (list 1 1 1 1) (list 1 5 7 3)) (list 1))

(define (intersection list1 list2)
  (filter (lambda (x) (member? x list2))
          (foldr (lambda (element-in-question list)
                   (cond                    
                     [(member? element-in-question list) list]
                     [else (cons element-in-question list)]))
                 (cond
                   [(empty? list1) empty]
                   [else (list (first list1))])
                 list1)))

;;Tests:
(check-expect (intersection (list 1 2 1 7) (list 1 1 1 5 2 2 7 3)) (list 2 7 1))
(check-expect (intersection (list 1 1 1 5 2 2 7 3) (list 1 2 1 7)) (list 2 7 1))
(check-expect (intersection (list 1 3 5 7) (list 0 2 4 6)) empty)
(check-expect (intersection (list 1 1 3 3 2 1) (list 1 2 3 1 4 5)) (list 3 2 1))
(check-expect (intersection (list #\i #\y #\i #\q) (list #\j #\y #\y #\y #\i))
              (list #\y #\i))
(check-expect (intersection (list (make-posn 4 5) 4 (make-posn 4.5 3.5) 5
                                  (make-posn 4 5) 7 (make-posn 6 7))
                            (list 4 (make-posn 1 1) (make-posn 4 5)
                                  (make-posn 4 5) (make-posn 4 5) 5
                                  (make-posn 4.5 3.5)))
              (list 4 (make-posn 4.5 3.5) 5 (make-posn 4 5)))
(check-expect (intersection (list "rowan" "hello" "there" "rowan")
                            (list "hello" "rowan" "there" "rowan"))
              (list "hello" "there" "rowan"))
(check-expect (intersection (list "Rowan" "hello!" "there," "rowan.")
                            (list "hello" "rowan" "there" "rowan"))
              empty)
(check-expect (intersection empty (list 1 5 7 3)) empty)
(check-expect (intersection (list 1 5 7 3) empty) empty)
(check-expect (intersection empty empty) empty)




;;******************************************************************************



;;part (b)

;;(union list1 list2) produces a list containing all the elements of list1 and
;;   list2 without any duplicates

;;union: (listof X) (listof Y) -> (listof (anyof X Y))

;;Examples:
(check-expect (union (list 3 4 2 1) (list 1 5 7 3)) (list 4 2 1 5 7 3))
(check-expect (union (list 3 4 4 2 2 1) (list 1 4 7 3))
              (list 2 1 4 7 3))
(check-expect (union empty empty)
              empty)

(define (union list1 list2)
  (foldr (lambda (element-in-question list)
           (cond
             [(member? element-in-question list) list]
             [else (cons element-in-question list)]))
         empty
         (foldr (lambda (to-be-combined list-so-far)
                  (cons to-be-combined list-so-far)) list2 list1)))

;;Tests:
(check-expect (union (list 1 2 3 4) (list 4 3 1 2)) (list 4 3 1 2))
(check-expect (union (list #\i #\r #\h #\a #\i)
                     (list #\n #\r #\a #\o #\w #\a #\n))
              (list #\h #\i #\r #\o #\w #\a #\n))
(check-expect (union (list (make-posn 1 1) 5 (make-posn 2 1) 6)
                     (list (make-posn 1 4) 4 (make-posn 2 1) 6
                           (make-posn 1 1) 7))
              (list 5 (make-posn 1 4) 4 (make-posn 2 1) 6 (make-posn 1 1) 7))
(check-expect (union empty (list 1 2))
              (list 1 2))
(check-expect (union (list 1 2) empty)
              (list 1 2))



;;******************************************************************************



;;part (c)

;;(unique-fn list pred) produces a list that removes all duplicates of 'list'
;;   according to the specified prodicate 'pred'

;;unique-fn: (listof X) (X Y -> Bool) -> (listof X)

;;Examples:
(check-expect (unique-fn (list 3 1 3) =) (list 1 3))
(check-expect (unique-fn (list 1 1.05 2 1.2) (lambda (x y)
                                               (> 0.1 (abs (- x y)))))
              (list 1.05 2 1.2))
(check-expect (unique-fn (list 15 20 25 30) (lambda (x y)
                                              (>= 10 (abs (- x y)))))
              (list 15 30))

(define (unique-fn list pred)
  (foldr (lambda (element-in-question list-so-far)
           (cond
             [(foldr (lambda (comparing-element result-so-far)
                       (or (pred element-in-question comparing-element)
                           result-so-far))
                     false list-so-far) list-so-far]
             [else (cons element-in-question list-so-far)]))
         empty list))

;;Tests:
(check-expect (unique-fn (list -3 1 3 -1) (lambda (x y)
                                            (= (- x) y))) (list 3 -1))
(check-expect (unique-fn (list 15 20 25 30) (lambda (x y)
                                              (> 10 (abs (- x y)))))
              (list 20 30))
(check-expect (unique-fn (list 30 15 20 25 30) (lambda (x y)
                                                 (<= 0 (abs (- x y)))))
              (list 30))
(check-expect (unique-fn (list 30 15 20 25 30) (lambda (x y)
                                                 (< 0 (abs (- x y)))))
              (list 30 30))
(check-expect (unique-fn (list #\q #\i #\y #\i #\q #\i #\y #\i) char=?)
              (list #\q #\y #\i))
(check-expect (unique-fn empty char=?)
              empty)



;;******************************************************************************



;;part (d)

;;(cross list1 list2) produces a list containing lists of all possible element
;;   pairs from list1 and list2

;;cross: (listof X) (listof Y) -> (listof (list X Y))

;;Examples:
(check-expect (cross (list 1 2 3 4) (list 3 2))
              (list (list 4 3) (list 4 2) (list 3 3) (list 3 2) (list 2 3)
                    (list 2 2) (list 1 3) (list 1 2)))
(check-expect (cross (list 1 0 1 0) (list 0 1 0 1))
              (list (list 0 0) (list 0 1) (list 0 0) (list 0 1)
                    (list 1 0) (list 1 1) (list 1 0) (list 1 1)
                    (list 0 0) (list 0 1) (list 0 0) (list 0 1)
                    (list 1 0) (list 1 1) (list 1 0) (list 1 1)))
(check-expect (cross (list #\a #\b) (list 0 1))
              (list (list #\b 0) (list #\b 1) (list #\a 0)
                    (list #\a 1)))

(define (cross list1 list2)
  (foldr (lambda (element-to-pair result-so-far)
           (foldr (lambda (to-be-combined list-so-far)
                    (cons to-be-combined list-so-far))
                  (map (lambda (x) (cons element-to-pair (list x))) list2)
                  result-so-far))
         empty list1))

;;Tests:
(check-expect (cross (list (make-posn 1 1) (make-posn 2 2))
                     (list (make-posn 0 0) (make-posn 3 3)))
              (list (list (make-posn 2 2) (make-posn 0 0))
                    (list (make-posn 2 2) (make-posn 3 3))
                    (list (make-posn 1 1) (make-posn 0 0))
                    (list (make-posn 1 1) (make-posn 3 3))))
(check-expect (cross empty empty) empty)
(check-expect (cross (list 1 2) empty) empty)
(check-expect (cross empty (list 1 2)) empty)
(check-expect (cross (list empty empty) (list 1 3))
              (list (list '() 1) (list '() 3)
                    (list '() 1) (list '() 3)))



;;******************************************************************************



;;part (e)

;;(jaccard list1 list2) produces the jaccard index of list1 and list2, defined
;;   as the size of the intersection of list1 and list2 divided by the size of
;;   the union of list1 and list2

;;jaccard: (listof Num) (listof Num) -> Num

;;requires: list1 and list2 are of equal length and are not both empty


;;Examples:
(check-expect (jaccard (list 1 4 2 8) (list 1 4 6 3)) 1/3)
(check-expect (jaccard (list 1 -4 2 8) (list 1 4 6 3)) 1/7)
(check-expect (jaccard (list 1 1 1) (list 2 2 2)) 0)

(define (jaccard list1 list2)
  (/ (length (intersection list1 list2)) (length (union list1 list2))))

;;Tests:
(check-expect (jaccard empty (list 1 2 3 4)) 0)
(check-expect (jaccard (list 1 2 3 4) empty) 0)
(check-expect (jaccard (list 1 2 3 4) (list .9 2.1 3 4.01)) 1/7)
(check-expect (jaccard (list 1 2 3) (list 3 2 1)) 1)



;;******************************************************************************



;;part (f)

;;(take list n) produces the first n elements in list, so all of list if n
;;   is greater than the length of list

;;take: (listof X) Nat -> (listof X)

;;Examples:
(check-expect (take (list 1 2 3) 1) (list 1))
(check-expect (take (list 1 2 3) 3) (list 1 2 3))
(check-expect (take (list 1 2 3) 20) (list 1 2 3))

(define (take list n)
  (cond
    [(>= n (length list)) list]
    [(> n 0) (cons (first list) (take (rest list) (sub1 n)))]
    [else empty]))

;;Tests:
(check-expect (take empty 20) empty)
(check-expect (take (list 1 2 3) 0) empty)
(check-expect (take (list 1 2 3) 4) (list 1 2 3))



;;******************************************************************************



;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 09, Problem 3
;;**********************************************



;;Given data definitions:
;; A Feature Vector (FV) is a (listof Num)
;;requires: A FV cannot be empty

;; A Document Identifier (DI) is a String

;; A Document Vector (DV) is a (list DI FV)

;; A Feature-Vector Association List (FV-AL) is one of
;; * empty
;; * (cons DV FV-AL)
;; require: each FV must be of the same length
;;          each DV must be unique

;; A Document Pair Tuple (DPT) is a (list DI DI Num)
;;    where Num corresponds to some similarity between
;;    the feature vectors associated with each DI



;;******************************************************************************



;;part (a)

;;(cmp-with-sim dv fv-al measure) produces a list of DPT whose elements contain 
;;   the DI of dv, the DI of the dv from fv-al that is currently being 
;;   proccessed, and the similarity amount of dv to the current dv being 
;;   proccessed according to measure

;;cmp-with-sim: DV FV-AL (FV FV -> Num) -> (listof DPT)

;;requires: The FV of dv and the FV of any of the DV in FV-AL cannot both be
;;   empty, this would make a divide by zero when computing the jaccard index
;;   (union would be zero)
;;   Also, the FV's of all the DV's must be equal length

;;Examples:
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4))
                            (list (list "t1" '(1 2 3 4)) (list "t2" '(2 5 1 6)))
                            jaccard)
              (list (list "t1" "t1" 1) (list "t1" "t2" 1/3)))
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4))
                            (list (list "t2" '(4 5 6 7)) (list "t3" '(5 6 7 8)))
                            jaccard)
              (list (list "t1" "t2" 1/7) (list "t1" "t3" 0)))
(check-expect (cmp-with-sim (list "t1" '(1 1 1 1))
                            (list (list "t2" '(1 1 1 1)) (list "t3" '(1 1 2 2))
                                  (list "t4" '(2 2 2 2)))
                            jaccard)
              (list (list "t1" "t2" 1) (list "t1" "t3" 1/2) (list "t1" "t4" 0)))

(define (cmp-with-sim dv fv-al measure)
  (foldr (lambda (current-dv dpt-so-far)
           (cons (list (first dv) (first current-dv)
                       (measure (second dv) (second current-dv))) dpt-so-far))
         empty fv-al))

;;Tests:
(check-expect (cmp-with-sim (list "t1" empty)
                            (list (list "t1" '(1 2 3 4)) (list "t2" '(2 5 1 6)))
                            jaccard)
              (list (list "t1" "t1" 0) (list "t1" "t2" 0)))
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4))
                            (list (list "t1" empty) (list "t2" empty))
                            jaccard)
              (list (list "t1" "t1" 0) (list "t1" "t2" 0)))
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4))
                            (list (list "t1" '(1 2 3 4)) (list "t2" empty))
                            jaccard)
              (list (list "t1" "t1" 1) (list "t1" "t2" 0)))
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4))
                            (list (list "t1" empty) (list "t2" '(1 2 3 4)))
                            jaccard)
              (list (list "t1" "t1" 0) (list "t1" "t2" 1)))
(check-expect (cmp-with-sim (list "t1" '(1 2 3 4)) empty jaccard) empty)



;;******************************************************************************



;;part (b)

;;(find-all-exact fv-al measure) produces a list of DPT of all unique, up to the  
;;   order of the pairs, of DI pairs from the DVs in fv-al which have the same   
;;   similarity measure, along with that measure

;;find-all-exact: FV-AL (FV FV -> Num) -> (listof DPT)

;;requries: The FV's of all the DV's must be equal length

;;Examples:
(check-expect (find-all-exact
               (list (list "t1" '(4 3 2 6)) (list "t2" '(4 5 3 8))
                     (list "t3" '(2 6 4 3)) (list "t4" '(8 3 4 5))) jaccard)
              (list (list "t3" "t1" 1)
                    (list "t1" "t3" 1)
                    (list "t4" "t2" 1)
                    (list "t2" "t4" 1)))
(check-expect (find-all-exact (list (list "t1" '(1 2 3 4))
                                    (list "t3" '(4 3 2 1))) jaccard)
              (list (list "t3" "t1" 1) (list "t1" "t3" 1)))
(check-expect (find-all-exact
               (list (list "t1" '(4 3 2 6)) (list "t2" '(4 5 3 8))
                     (list "t3" '(2 6 4 4))) jaccard) empty)

(define (find-all-exact fv-al measure)
  (unique-fn
   (foldr
    (lambda (dv-in-question dpt-list-so-far)
      (foldr (lambda (to-be-combined list-so-far)
               (cons to-be-combined list-so-far))
             dpt-list-so-far
             (foldr (lambda (dv-being-processed already-processed-fv-al)
                      (foldr (lambda (to-be-combined list-so-far)
                               (cons to-be-combined list-so-far))
                             already-processed-fv-al
                             (cond [(and (= 1 (measure
                                               (second dv-being-processed)
                                               (second dv-in-question)))
                                         (not (equal?
                                               (first dv-being-processed)
                                               (first dv-in-question))))
                                    (list (list (first dv-in-question)
                                                (first dv-being-processed) 1)
                                          (list (first dv-being-processed)
                                                (first dv-in-question) 1))]
                                   [else empty]))) empty fv-al)))
    empty fv-al) equal?))

;;Tests:
(check-expect (find-all-exact (list (list "t1" '(1 2 3)) (list "t2" '(1 2 4))
                                    (list "t3" '(1 2 5)) (list "t4" '(3 1 2))
                                    (list "t5" '(1 5 2)) (list "t6" '(5 2 1))
                                    (list "t7" '(1 4 2))) jaccard)
              (list (list "t4" "t1" 1) (list "t1" "t4" 1) (list "t5" "t3" 1)
                    (list "t3" "t5" 1) (list "t6" "t3" 1) (list "t3" "t6" 1)
                    (list "t6" "t5" 1) (list "t5" "t6" 1) (list "t7" "t2" 1)
                    (list "t2" "t7" 1)))
(check-expect (find-all-exact empty jaccard)
              empty)
(check-expect (find-all-exact (list (list "t1" '(1 2 3)) (list "t2" '(1 2 4))
                                    (list "t3" '(1 2 5))) jaccard)
              empty)
(check-expect (find-all-exact (list (list "t1" '(1)) (list "t2" '(1))
                                    (list "t3" '(1)) (list "t4" '(1))) jaccard)
              (list (list "t2" "t1" 1) (list "t1" "t2" 1) (list "t3" "t1" 1)
                    (list "t1" "t3" 1) (list "t3" "t2" 1) (list "t2" "t3" 1)
                    (list "t4" "t1" 1) (list "t1" "t4" 1) (list "t4" "t2" 1)
                    (list "t2" "t4" 1) (list "t4" "t3" 1) (list "t3" "t4" 1)))



;;******************************************************************************



;;part (c)

;;(redundant? dpt1 dpt2) produces true if dpt1 and dpt2 only differ by the
;;   order of their DI's, false otherwise

;;redundant?: DPT DPT -> Bool

;;Examples:
(check-expect (redundant? (list "t1" "t2" 1) (list "t2" "t1" 1)) true)
(check-expect (redundant? (list "t1" "t3" 1) (list "t1" "t2" 1)) false)
(check-expect (redundant? (list "t1" "t2" 1) (list "t2" "t1" 2)) true)

(define (redundant? dpt1 dpt2)
  (and (member? (first dpt1) dpt2) (member? (second dpt1) dpt2)))

;;Tests:
(check-expect (redundant? (list "t1" "t3" 1) (list "t1" "t3" 1)) true)
(check-expect (redundant? (list "t3" "t1" 1) (list "t1" "t3" 1)) true)
(check-expect (redundant? (list "t3" "t2" 1) (list "t1" "t3" 1)) false)



;;******************************************************************************



;;part (d)

;;(find-similar-within-d fv-al d measure) produces a list of DPT of all unique,   
;;   up to and including the order of the pairs (ie no redundancy as defined in    
;;   part c), of DI pairs from the DVs in fv-al whose similarity is strictly 
;;   greater than d, along with that similarity measure

;;find-similar-within-d: FV-AL Num (FV FV -> Num) -> (listof DPT)

;;requires: d is within [0,1]

;;Examples:
(check-expect (find-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(0 0 0 1))) .5 jaccard)
              (list (list "t1" "t2" 0.6) (list "t1" "t3" 1)
                    (list "t2" "t3" 0.6)))
(check-expect (find-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(0 0 0 1))) .6 jaccard)
              (list (list "t1" "t3" 1)))
(check-expect (find-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1))) 0 jaccard)
              (list (list "t1" "t2" 0.6) (list "t1" "t3" 1) (list "t2" "t3" 0.6)
                    (list "t1" "t4" 1/7) (list "t2" "t4" 1/7)
                    (list "t3" "t4" 1/7)))

(define (find-similar-within-d fv-al d measure)
  (unique-fn
   (foldr
    (lambda (dv-in-question dpt-list-so-far)
      (foldr (lambda (to-be-combined list-so-far)
               (cons to-be-combined list-so-far))
             dpt-list-so-far
             (foldr (lambda (dv-being-processed already-processed-fv-al)
                      (foldr (lambda (to-be-combined list-so-far)
                               (cons to-be-combined list-so-far))
                             already-processed-fv-al
                             (cond [(and (< d (measure
                                               (second dv-being-processed)
                                               (second dv-in-question)))
                                         (not (equal? (first dv-being-processed)
                                                      (first dv-in-question))))
                                    (list (list (first dv-being-processed) 
                                                (first dv-in-question)
                                                (measure
                                                 (second dv-being-processed)
                                                 (second dv-in-question))))]
                                   [else empty]))) empty fv-al)))
    empty fv-al) redundant?))

;;Tests:
(check-expect (find-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1))) 1/7
                                                                      jaccard)
              (list (list "t1" "t2" 0.6) (list "t1" "t3" 1)
                    (list "t2" "t3" 0.6)))
(check-expect (find-similar-within-d empty 1/7 jaccard) empty)
(check-expect (find-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1))) (/ 1 7.01)
                                                                      jaccard)
              (list (list "t1" "t2" 0.6) (list "t1" "t3" 1) (list "t2" "t3" 0.6)
                    (list "t1" "t4" 1/7) (list "t2" "t4" 1/7)
                    (list "t3" "t4" 1/7)))



;;******************************************************************************



;;part (e)

;;(find-k-similar-within-d fv-al d k measure) produces a list of k DPT, selected    
;;   on the basis of most similar, of all unique, up to and including the order    
;;   of the pairs (ie no redundancy as defined in  part c), of DI pairs from the  
;;   DVs in fv-al whose similarity is strictly greater than d, along with that
;;   similarity measure

;;find-k-similar-within-d: FV-AL Num Nat (FV FV -> Num) -> (listof DPT)

;;requires: d is within [0,1] and k is a positive integer (non-zero nat)

;;Examples:
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1))) .5 2 jaccard)
              (list (list "t1" "t3" 1) (list "t1" "t2" 0.6)))
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1))) .5 100 jaccard)
              (list (list "t1" "t3" 1) (list "t1" "t2" 0.6) 
                    (list "t2" "t3" 0.6)))
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1)))
               1/7 1 jaccard)
              (list (list "t1" "t3" 1)))

(define (find-k-similar-within-d fv-al d k measure)
  (take
   (sort (find-similar-within-d fv-al d measure)
         (lambda (x y) (> (third x) (third y)))) k))

;;Tests
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1)))
               1/7 5 jaccard)
              (list (list "t1" "t3" 1) (list "t1" "t2" 0.6) 
                    (list "t2" "t3" 0.6)))
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1)))
               1/7 0 jaccard) empty)
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1)))
               .999 100 jaccard) (list (list "t1" "t3" 1)))
(check-expect (find-k-similar-within-d
               (list (list "t1" '(1 2 3 4)) (list "t2" '(5 3 2 1))
                     (list "t3" '(4 3 2 1)) (list "t4" '(20 30 9 1)))
               (/ 1 7.01) 100 jaccard)
              (list (list "t1" "t3" 1) (list "t1" "t2" 0.6) (list "t2" "t3" 0.6)
                    (list "t1" "t4" 1/7) (list "t2" "t4" 1/7)
                    (list "t3" "t4" 1/7)))
