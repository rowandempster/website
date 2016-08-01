;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 06, Problem 4
;;**********************************************

;;*********  Note   ********

;;For part (d), I made the function accept unsorted Priority Lists,
;;   which I now realize is wrong, it should accpet unsorted patient profiles..
;;   However, it is due in 9 minutes, so I included my attempt at the correct
;;   function, and named my incorrect one "my-sort-priority-list"
;;   Midterms eh?




;;part (a)

;;(calc-BPSys sysBP) produces the BPSys of a patient using their systolic
;;   blood pressure

;;calc-BPSys: Int -> Int

;;required: sysBP is positive

;;Examples:
(check-expect (calc-BPSys 40) 30)
(check-expect (calc-BPSys 80) 0)
(check-expect (calc-BPSys 160) 10)

(define (calc-BPSys sysBP)
  (cond
    [(> 70 sysBP) (- 70 sysBP)]
    [(< 150 sysBP) (- sysBP 150)]
    [else 0]))

;;Tests:
(check-expect (calc-BPSys 1) 69)
(check-expect (calc-BPSys 69) 1)
(check-expect (calc-BPSys 70) 0)
(check-expect (calc-BPSys 150) 0)
(check-expect (calc-BPSys 151) 1)
(check-expect (calc-BPSys 300) 150)


;;(calc-Oxy oxygenation) produces the Oxy of a patient using their oxygenation

;;calc-Oxy Num -> Num

;;required: oxygenation is positive

;;Examples:
(check-expect (calc-Oxy 40) (expt 2 50))
(check-expect (calc-Oxy 80) 1024)
(check-expect (calc-Oxy 160) 0)

(define (calc-Oxy oxygenation)
  (cond
    [(<= 90 oxygenation) 0]
    [else (expt 2 (- 90 oxygenation))]))

;;Tests:
(check-expect (calc-Oxy 1) (expt 2 89))
(check-expect (calc-Oxy 89) 2)
(check-expect (calc-Oxy 90) 0)
(check-expect (calc-Oxy 150) 0)



;;(calc-TempF temp) produces the TempF of a patient using their temp

;;calc-TempF Num -> Num

;;required: temp is positive

;;Examples:
(check-expect (calc-TempF 40) 55)
(check-expect (calc-TempF 100) 0)
(check-expect (calc-TempF 160) 56)

(define (calc-TempF temp)
  (cond
    [(> 95 temp) (- 95 temp)]
    [(< 104 temp) (- temp 104)]
    [else 0]))

;;Tests:
(check-expect (calc-TempF 1) 94)
(check-expect (calc-TempF 94) 1)
(check-expect (calc-TempF 95) 0)
(check-expect (calc-TempF 104) 0)
(check-expect (calc-TempF 105) 1)
(check-expect (calc-TempF 400) 296)



;;(patient-severity pprof) produces the severity score of PProf using the
;;   formula S = 0.5*BPSys + Oxy + TempF

;;patient-severity: (listof Str Int Num Num) -> Num

;;Examples:
(check-expect (patient-severity (list "Rowan" 40 80 100)) 1039)
(check-expect (patient-severity (list "Owen" 80 89 94)) 3)
(check-expect (patient-severity (list "Aidan" 160 89 1)) 101)

(define (patient-severity pprof)
  (cond
    [else (+ (* 0.5 (calc-BPSys (second pprof)))
             (calc-Oxy (third pprof))
             (calc-TempF (fourth pprof)))]))

;;Test:
(check-expect (patient-severity (list "Matt" 1 89 1)) 130.5)
(check-expect (patient-severity (list "Becky" 80 90 104)) 0)
(check-expect (patient-severity (list "Lewis" 300 80 400)) 1395)



;;******************************************************************************



;;part (b)

;; A Priority-List (PList) is a (listof (list Num Patient-Profile)) where
;;   a Patient-Profile (PProf) is a (listof Str Int Num Num)
;;requires: A Priority-List must be sorted from largest to smallest
;;          patient severity

;;Arbitary Function Template:
;; my-plist-fn: PList -> Any
(define (my-plist-fn plist)
  (cond
    [(... (first plist)) ... ]
    [else (... (rest plist) ...
               (my-plist-fun (... plist...)))]))



;;******************************************************************************



;;part (c)

;;(insert-priority-list plist pprof) produces a new priority list with pprof
;;   inserted into its place (according to its severity score)

;;insert-priority-list: PList PProf -> PList

;;Examples:
(check-expect (insert-priority-list (list
                                     (list 1395 (list "Lewis" 300 80 400))
                                     (list 1039 (list "Rowan" 40 80 100))
                                     (list 0 (list "Becky" 80 90 104)))
                                    (list "Matt" 1 89 1))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (insert-priority-list (list
                                     (list 1039 (list "Rowan" 40 80 100))
                                     (list 130.5 (list "Matt" 1 89 1))
                                     (list 0 (list "Becky" 80 90 104)))
                                    (list "Lewis" 300 80 400))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (insert-priority-list (list
                                     (list 1395 (list "Lewis" 300 80 400))
                                     (list 1039 (list "Rowan" 40 80 100))
                                     (list 130.5 (list "Matt" 1 89 1)))
                                    (list "Becky" 80 90 104))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))

(define (insert-priority-list plist pprof)
  (cond
    [(empty? plist) (cons (list (patient-severity pprof) pprof) plist)]
    [(>= (patient-severity pprof) (first (first plist)))
     (cons (list (patient-severity pprof) pprof) plist)]
    [else (cons (first plist) (insert-priority-list (rest plist) pprof))]))

;;Tests:
(check-expect (insert-priority-list (list
                                     (list 89.5 (list "Tom" 23 98 29))
                                     (list 65.5 (list "Nick" 23 93 53))
                                     (list 9 (list "Ryan" 94 983 86)))
                                    (list "Steve" 25 100 86))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Steve" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (insert-priority-list (list
                                     (list 89.5 (list "Tom" 23 98 29))
                                     (list 65.5 (list "Nick" 23 93 53))
                                     (list 31.5 (list "Steve" 25 100 86)))
                                    (list "Ryan" 94 983 86))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Steve" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (insert-priority-list (list
                                     (list 65.5 (list "Nick" 23 93 53))
                                     (list 31.5 (list "Steve" 25 100 86))
                                     (list 9 (list "Ryan" 94 983 86)))
                                    (list "Tom" 23 98 29))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Steve" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))



;;******************************************************************************



;; part (d)

;;(my-sort-priority-list lopprof) produces a Priority-List that is the sorted
;;   version of lopprof

;;my-sort-priority-list: (listof PProf) -> Plist

;;requires: lopprof is an unsorted list of PProfs

;;Examples:
(check-expect (my-sort-priority-list (list
                                   (list 1039 (list "Rowan" 40 80 100))
                                   (list 0 (list "Becky" 80 90 104))
                                   (list 130.5 (list "Matt" 1 89 1))
                                   (list 1395 (list "Lewis" 300 80 400))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (my-sort-priority-list (list
                                   (list 1395 (list "Lewis" 300 80 400))
                                   (list 130.5 (list "Matt" 1 89 1))
                                   (list 1039 (list "Rowan" 40 80 100))
                                   (list 0 (list "Becky" 80 90 104))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (my-sort-priority-list (list
                                   (list 89.5 (list "Tom" 23 98 29))
                                   (list 31.5 (list "Anne" 25 100 86))
                                   (list 9 (list "Ryan" 94 983 86))
                                   (list 65.5 (list "Nick" 23 93 53))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))

(define (my-sort-priority-list lopprof)
  (cond
    [(empty? lopprof) empty]
    [else (insert-priority-list (my-sort-priority-list (rest lopprof))
                                (first (rest (first lopprof))))]))

(define (sort-priority-list lopprof)
  (cond
    [(empty? lopprof) empty]
    [else (insert-priority-list (my-sort-priority-list (rest lopprof))
                                (list (patient-severity (first (first lopprof))) (first (first lopprof))))]))

;;Tests:
(check-expect (my-sort-priority-list (list
                                   (list 9 (list "Ryan" 94 983 86))
                                   (list 31.5 (list "Anne" 25 100 86))
                                   (list 89.5 (list "Tom" 23 98 29))
                                   (list 65.5 (list "Nick" 23 93 53))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (my-sort-priority-list (list
                                   (list 89.5 (list "Tom" 23 98 29))
                                   (list 9 (list "Ryan" 94 983 86))
                                   (list 31.5 (list "Anne" 25 100 86))
                                   (list 65.5 (list "Nick" 23 93 53))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (my-sort-priority-list (list
                                   (list 9 (list "Ryan" 94 983 86))
                                   (list 31.5 (list "Anne" 25 100 86))
                                   (list 65.5 (list "Nick" 23 93 53))
                                   (list 89.5 (list "Tom" 23 98 29))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))





;;******************************************************************************



;; part (e)

;;(merge-priority-list plist1 plist2) produces a new PList containing all of
;;   the pairs of severity scores and patient profiles of plist1 and plist2

;;merge-priority-list: PList PList -> PList

;;Examples:
(check-expect (merge-priority-list
               (list
                (list 89.5 (list "Tom" 23 98 29))
                (list 65.5 (list "Nick" 23 93 53))
                (list 31.5 (list "Anne" 25 100 86))
                (list 9 (list "Ryan" 94 983 86)))
               (list
                (list 1395 (list "Lewis" 300 80 400))
                (list 1039 (list "Rowan" 40 80 100))
                (list 130.5 (list "Matt" 1 89 1))
                (list 0 (list "Becky" 80 90 104))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (merge-priority-list
               (list
                (list 89.5 (list "Tom" 23 98 29)))
               (list
                (list 130.5 (list "Matt" 1 89 1))
                (list 0 (list "Becky" 80 90 104))))
              (list
               (list 130.5 (list "Matt" 1 89 1))
               (list 89.5 (list "Tom" 23 98 29))
               (list 0 (list "Becky" 80 90 104))))

(define (merge-priority-list plist1 plist2)
  (my-sort-priority-list (append plist1 plist2)))

;;Tests:
(check-expect (merge-priority-list
               (list
                (list 130.5 (list "Matt" 1 89 1))
                (list 89.5 (list "Tom" 23 98 29))
                (list 0 (list "Becky" 80 90 104)))
               (list
                (list 130.5 (list "Matt" 1 89 1))
                (list 0 (list "Becky" 80 90 104))
                (list 89.5 (list "Tom" 23 98 29))))
              (list
               (list 130.5 (list "Matt" 1 89 1))
               (list 130.5 (list "Matt" 1 89 1))
               (list 89.5 (list "Tom" 23 98 29))
               (list 89.5 (list "Tom" 23 98 29))
               (list 0 (list "Becky" 80 90 104))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (merge-priority-list
               (list
                (list 89.5 (list "Tom" 23 98 29))
                (list 0 (list "Becky" 80 90 104)))
               (list
                (list 130.5 (list "Matt" 1 89 1))
                (list 0 (list "Becky" 80 90 104))))
              (list
               (list 130.5 (list "Matt" 1 89 1))
               (list 89.5 (list "Tom" 23 98 29))
               (list 0 (list "Becky" 80 90 104))
               (list 0 (list "Becky" 80 90 104))))




;;******************************************************************************



;;part (f)

;;(fix-priority-list plist) produces a new Priority-List that does not contain
;;   any faulty patient-profile entries

;;fix-priority-list: PList -> PList

;;Examples:
(check-expect (fix-priority-list (list
                                  (list 32 (list "Ryan" 94 983 86))
                                  (list 31 (list "Anne" 25 100 86))
                                  (list 12 (list "Nick" 23 93 53))
                                  (list 10 (list "Tom" 23 98 29))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (fix-priority-list (list
                                  (list 34 (list "Ryan" 94 983 86))
                                  (list 23 (list "Anne" 25 100 86))
                                  (list 0 (list "Nick" 23 93 53))
                                  (list 0 (list "Tom" 23 98 29))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))
(check-expect (fix-priority-list (list
                                  (list 10000 (list "Ryan" 94 983 86))
                                  (list 100 (list "Anne" 25 100 86))
                                  (list 0 (list "Nick" 23 93 53))
                                  (list -10 (list "Tom" 23 98 29))))
              (list
               (list 89.5 (list "Tom" 23 98 29))
               (list 65.5 (list "Nick" 23 93 53))
               (list 31.5 (list "Anne" 25 100 86))
               (list 9 (list "Ryan" 94 983 86))))

(define (fix-priority-list plist)
  (cond
    [(empty? plist) empty]
    [else (my-sort-priority-list(cons (list (patient-severity
                                          (first (rest (first plist))))
                                         (first (rest (first plist))))
                                   (fix-priority-list (rest plist))))]))

;;Tests:
(check-expect (fix-priority-list (list
                                  (list 0 (list "Lewis" 300 80 400))
                                  (list -1 (list "Rowan" 40 80 100))
                                  (list -2 (list "Matt" 1 89 1))
                                  (list -100 (list "Becky" 80 90 104))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (fix-priority-list (list
                                  (list 1395 (list "Lewis" 300 80 400))
                                  (list 1039 (list "Rowan" 40 80 100))
                                  (list 130.5 (list "Matt" 1 89 1))
                                  (list 0 (list "Becky" 80 90 104))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))
(check-expect (fix-priority-list (list
                                  (list 0 (list "Lewis" 300 80 400))
                                  (list 0 (list "Rowan" 40 80 100))
                                  (list 0 (list "Matt" 1 89 1))
                                  (list 0 (list "Becky" 80 90 104))))
              (list
               (list 1395 (list "Lewis" 300 80 400))
               (list 1039 (list "Rowan" 40 80 100))
               (list 130.5 (list "Matt" 1 89 1))
               (list 0 (list "Becky" 80 90 104))))













