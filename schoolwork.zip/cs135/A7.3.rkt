;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 07, Problem 3
;;**********************************************

;;Given data definitions:
(define-struct supervisor (id subordinates))
;; A Supervisor is a (make-supervisor Nat (listof Org-Chart))
;; requires: id values are unique

;; An Org-Chart is one of:
;;* Nat
;;* Supervisor

;;Example Org-Chart:

(define ex-org-chart (make-supervisor
                      10
                      (list (make-supervisor 9 (list 6 5))
                            8
                            (make-supervisor
                             7
                             (list 4
                                   (make-supervisor
                                    3
                                    (list
                                     (make-supervisor 2
                                                      (list 1)))))))))
(define ex-org-chart-2
  (make-supervisor 10
                   (list (make-supervisor
                          8
                          (list (make-supervisor
                                 15
                                 (list (make-supervisor
                                        16
                                        (list
                                         17 (make-supervisor
                                             18
                                             (list 19))))))))
                         (make-supervisor
                          7
                          (list (make-supervisor
                                 6
                                 (list 2 1))
                                (make-supervisor
                                 5
                                 (list 11 12))
                                (make-supervisor
                                 4
                                 (list 13))
                                3)))))



;;******************************************************************************



;;part (a)

;;(direct-reports org-chart id) produces a list of all staff ID's that are
;;   under the supervisor with ID 'id'. If id does not exist in org-chart
;;   or is not a supervisor, prodocues a empty list

;;direct-reports: Org-Chart Nat -> (listof Nat)

;;Examples:
(check-expect (direct-reports (make-supervisor 1 (list 2)) 1) (list 2))
(check-expect (direct-reports (make-supervisor 1 (list 2 3 4)) 1) (list 2 3 4))
(check-expect (direct-reports
               (make-supervisor 5
                                (list (make-supervisor 4 (list 2 3))
                                      5 6)) 5) (list 4 2 3 5 6))

(define (direct-reports org-chart id)
  (cond
    [(or (empty? org-chart) (number? org-chart)) empty]
    [(and (cons? org-chart)
          (not (number? (first org-chart)))
          (= id (supervisor-id (first org-chart))))
     (get-subs (first org-chart))]
    [(cons? org-chart) (append (direct-reports (first org-chart) id)
                               (direct-reports (rest org-chart) id))]
    [(= id (supervisor-id org-chart)) (get-subs org-chart)]
    [else (direct-reports (supervisor-subordinates org-chart) id)]))

;;Tests:
(check-expect (direct-reports
               (make-supervisor 5
                                (list (make-supervisor 4 (list 2 3))
                                      5 6)) 4) (list 2 3))
(check-expect (direct-reports (make-supervisor 1 (list 2 3 4)) 2) empty)
(check-expect (direct-reports (make-supervisor 1 (list 2 3 4)) 5) empty)
(check-expect (direct-reports ex-org-chart 10) (list 9 6 5 8 7 4 3 2 1))
(check-expect (direct-reports ex-org-chart 8) empty)
(check-expect (direct-reports ex-org-chart 11) empty)
(check-expect (direct-reports ex-org-chart 7) (list 4 3 2 1))
(check-expect (direct-reports ex-org-chart 4) empty)
(check-expect (direct-reports ex-org-chart 3) (list 2 1))
(check-expect (direct-reports ex-org-chart 2) (list 1))
(check-expect (direct-reports ex-org-chart 9) (list 6 5))
(check-expect (direct-reports ex-org-chart 6) empty)
(check-expect (direct-reports ex-org-chart 5) empty)
(check-expect (direct-reports ex-org-chart 1) empty)
(check-expect (direct-reports 1 1) empty)
(check-expect (direct-reports empty 1) empty)
(check-expect (direct-reports ex-org-chart-2 1) empty)
(check-expect (direct-reports ex-org-chart-2 8) (list 15 16 17 18 19))
(check-expect (direct-reports ex-org-chart-2 5) (list 11 12))
(check-expect (direct-reports ex-org-chart-2 7) (list 6 2 1 5 11 12 4 13 3))



;;(get-subs org-chart) produces a list of the ids of the subordinates of the  
;;  root supervisor of org-chart. If org-chart is not a supervisor, produces
;;  empty.

;;get-subs: Org-Chart -> (listof Nat)

;;Examples:
(check-expect (get-subs (make-supervisor 5
                                         (list (make-supervisor 4 (list 2 3))
                                               5 6))) (list 4 2 3 5 6))
(check-expect (get-subs
               ex-org-chart)
              (list 9 6 5 8 7 4 3 2 1))
(check-expect (get-subs 5) empty)

(define (get-subs org-chart)
  (cond
    [(or (number? org-chart) (empty? (supervisor-subordinates org-chart)))
     empty]
    [(supervisor? (first (supervisor-subordinates org-chart)))
     (append
      (cons
       (supervisor-id (first (supervisor-subordinates org-chart)))
       (get-subs (first (supervisor-subordinates org-chart))))
      (get-subs (make-supervisor
                 (supervisor-id org-chart)
                 (rest (supervisor-subordinates org-chart)))))]
    [else (append
           (list (first (supervisor-subordinates org-chart)))
           (get-subs (make-supervisor
                      (supervisor-id org-chart)
                      (rest (supervisor-subordinates org-chart)))))]))

;;Tests:
(check-expect (get-subs (make-supervisor
                         7
                         (list 4
                               (make-supervisor
                                3
                                (list
                                 (make-supervisor 2
                                                  (list 1)))))))
              (list 4 3 2 1))
(check-expect (get-subs (make-supervisor
                         3
                         (list
                          (make-supervisor 2
                                           (list 1)))))
              (list 2 1))
(check-expect (get-subs (make-supervisor
                         1 (list 2 (make-supervisor 3
                                                    (list 4 5)))))
              (list 2 3 4 5))
(check-expect (get-subs ex-org-chart-2)
              (list 8 15 16 17 18 19 7 6 2 1 5 11 12 4 13 3))



;;******************************************************************************



;;part (b)

;;(vacation-approval org-chart id) produces the id's of all staff members who
;;   can approve the staff member with ID 'id' vacation request (ie their
;;   direct or indirect supervisors). If no id exists or is the CEO, empty.

;;vacation-approval: Org-Chart Nat -> (listof Nat)

;;Examples:
(check-expect (vacation-approval ex-org-chart 1) (list 2 3 7 10))
(check-expect (vacation-approval ex-org-chart 2) (list 3 7 10))
(check-expect (vacation-approval ex-org-chart 10) empty)

(define (vacation-approval org-chart id)
  (vacation-approval-acc org-chart id empty))

;;Tests:
(check-expect (vacation-approval ex-org-chart 11) empty)
(check-expect (vacation-approval ex-org-chart 6) (list 9 10))
(check-expect (vacation-approval ex-org-chart 4) (list 7 10))
(check-expect (vacation-approval ex-org-chart 8) (list 10))
(check-expect (vacation-approval ex-org-chart 9) (list 10))
(check-expect (vacation-approval ex-org-chart 7) (list 10))



;;(vacation-approval-acc org-chart id super-acc) accumulates supervisors as it
;;   goes down the org-chart until it finds id and then produces the list
;;   of accumulated supervisor id's

;;vacation-approval-acc: Org-Chart Nat (listof Nat) -> (listof Nat)

;;requires: super-acc's original input is an empty list

;;Exampels:
(check-expect (vacation-approval-acc ex-org-chart-2 19 empty)
              (list 18 16 15 8 10))
(check-expect (vacation-approval-acc ex-org-chart-2 18 empty)
              (list 16 15 8 10))
(check-expect (vacation-approval-acc ex-org-chart-2 17 empty)
              (list 16 15 8 10))

(define (vacation-approval-acc org-chart id super-acc)
  (cond
    [(empty? org-chart) empty]
    [(cons? org-chart)
     (append (vacation-approval-acc (first org-chart) id super-acc)
             (vacation-approval-acc (rest org-chart) id super-acc))]
    [(or (and (number? org-chart) (= id org-chart))
         (and (supervisor? org-chart) (= id (supervisor-id org-chart))))
     super-acc]
    [(number? org-chart) empty]
    [(supervisor? org-chart)
     (vacation-approval-acc (supervisor-subordinates org-chart)
                            id
                            (cons (supervisor-id org-chart) super-acc))]))

;;Tests:
(check-expect (vacation-approval-acc ex-org-chart-2 16 empty)
              (list 15 8 10))
(check-expect (vacation-approval-acc ex-org-chart-2 10 empty)
              empty)
(check-expect (vacation-approval-acc ex-org-chart-2 7 empty)
              (list 10))
(check-expect (vacation-approval-acc ex-org-chart-2 5 empty)
              (list 7 10))
(check-expect (vacation-approval-acc ex-org-chart-2 3 empty)
              (list 7 10))
(check-expect (vacation-approval-acc ex-org-chart-2 11 empty)
              (list 5 7 10))
(check-expect (vacation-approval-acc ex-org-chart-2 2 empty)
              (list 6 7 10))
(check-expect (vacation-approval-acc ex-org-chart-2 25 empty)
              empty)
(check-expect (vacation-approval-acc ex-org-chart-2 1 empty)
              (list 6 7 10))












