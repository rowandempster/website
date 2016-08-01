;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 10, Problem 1
;;**********************************************



;;(mergesort lst compare) produces lst sorted accoding to the
;;   comparison function 'compare'

;;mergesort: (listof X) (X X -> Bool) -> (listof X)

;;requires: 'compare' is a less than or greater than comparator function
;;   which applies to type X

;;Examples:
(check-expect (mergesort (list 4 2 6 4 8 2) <) (list 2 2 4 4 6 8))
(check-expect (mergesort (list 4 2 6 4 8 2) >) (list 8 6 4 4 2 2))
(check-expect (mergesort (list "q" "g" "r" "y" "q" "f") string<?)
              (list "f" "g" "q" "q" "r" "y"))

(define (mergesort lst compare)
  (local
    ;;(first-half lst) produces the first half of lst, including the middle
    ;;   element if there is one
    ;;first-half: (listof X) -> (listof X)
    [(define (first-half lst)
       (foldl (lambda (x y)
                (cond
                  [(>= (length y) (/ (length lst) 2)) y]
                  [else (append y (list x))])) empty lst))
     ;;(second-half lst) produces the second half of lst, exluding the middle
     ;;   element if there is one
     ;;second-half: (listof X) -> (listof X)
     (define (second-half lst)
       (foldr (lambda (x y)
                (cond
                  [(>= (+ (length y) .5) (/ (length lst) 2)) y]
                  [else (cons x y)])) empty lst))
     ;;(merge slst1 slst2 compare) procudes a sorted list out of slst1 and slst2
     ;;   accoding to the comparison function 'compare'
     ;;merge: (listof X) (listof X) (X X -> Bool) -> (listof X)
     ;;requires: slst1 and slst2 are sotred according to 'compare' and 'compare'
     ;;   'compare' is a less than or greater than comparator function 
     (define (merge slst1 slst2 compare)
       (cond
         [(empty? slst1) slst2]
         [(empty? slst2) slst1]
         [(compare (first slst1) (first slst2))
          (cons (first slst1) (merge (rest slst1) slst2 compare))]
         [else (cons (first slst2) (merge slst1 (rest slst2) compare))]))]
    (cond
      [(or (= 1 (length lst)) (= 0 (length lst))) lst]
      [else (merge (mergesort (first-half lst) compare)
                   (mergesort (second-half lst) compare) compare)])))

;;Tests:
(check-expect (mergesort empty <) empty)
(check-expect (mergesort (list 1) <) (list 1))
(check-expect (mergesort (list 2 1) <) (list 1 2))
(check-expect (mergesort (list 2 1 2) <) (list 1 2 2))
(check-expect (mergesort (list 2 1 2) >) (list 2 2 1))
(check-expect (mergesort (list #\h #\j #\q #\r #\a #\r #\b #\e) char<?)
              (list #\a #\b #\e #\h #\j #\q #\r #\r))
(check-expect (mergesort (list #\b #\c #\f #\b #\a #\f) char>?)
              (list #\f #\f #\c #\b #\b #\a))




