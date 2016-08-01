;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 07, Problem 2
;;**********************************************


;;Given data definitions:
(define-struct staff-node (staff left right))

;; A Staff-Node is a (make-staff-node Staff-Member Staff-BST Staff-BST)
;; requires: ids of all Staff-Member on the left subtree are smaller than the
;;   id of Staff-Member and ids of all Staff-Member on the right subtree are
;    larger than the id of Staff-Member

;; A Staff-BST is one of:
;;* empty
;;* Staff-Node

(define-struct staff-member (id name dept))
;; A Staff-Member is a (make-staff-member Nat Str Str)
;; requires: id is unique
;; (i.e., every staff-member with the same id also has the same name)

(define-struct salary (staff-id base bonus))
;; A Salary is a (make-salary Nat Num Num)
;; requires: base, bonus ≥ 0

;; A Staff-List is a (listof Staff-Member)
;; requires: elements are sorted by increasing id

;; A Sal-List is a (listof Salary)



;;Given Examples:
(define staff1 (make-staff-member 1 "John" "Engineering"))
(define staff2 (make-staff-member 2 "Adam" "R&D"))
(define staff3 (make-staff-member 3 "Albert" "Engineering"))
(define staff4 (make-staff-member 4 "Liz" "Finance"))
(define staff5 (make-staff-member 5 "Anne" "Defence"))
(define staff6 (make-staff-member 6 "Suzy" "R&D"))
(define staff7 (make-staff-member 7 "Leslie" "R&D"))
(define staff8 (make-staff-member 8 "Josh" "Engineering"))
(define staff9 (make-staff-member 9 "Rowan" "Software Engineer"))
(define staff10 (make-staff-member 10 "Old Rowan" "CEO"))

(define salary1 (make-salary 1 49000 10))
(define salary2 (make-salary 2 49000 1000))
(define salary3 (make-salary 3 50000 1))
(define salary4 (make-salary 4 60000 0))
(define salary5 (make-salary 5 93000 100))
(define salary6 (make-salary 6 68500 0))
(define salary7 (make-salary 7 250000 0))
(define salary8 (make-salary 8 99999 2))
(define salary9 (make-salary 9 150000 10))
(define salary10 (make-salary 10 600000 500))

(define staff-list (list staff1 staff2 staff3 staff4 staff5 staff6 staff7
                         staff8))

(define given-sal-list (list salary1 salary2 salary3 salary4 salary7 salary8
                             salary9))

(define sal-list (list salary1 salary2 salary3 salary4 salary5 salary6
                       salary7 salary8 salary9 salary10))



;;******************************************************************************



;;part (a)

;;(add-staff-bst staff-bst staff-member) produces a new Staff-BST that is
;;   staff-bst with staff-member added to it

;;add-staff-bst: Staff-BST Staff-Member -> Staff-BST

;;requires: no Staff-Member in staff-bst had the same ID as staff-member

;;Examples:
(check-expect (add-staff-bst (make-staff-node staff2 empty empty) staff1)
              (make-staff-node staff2
                               (make-staff-node staff1 empty empty)
                               empty))
(check-expect (add-staff-bst (make-staff-node staff2 empty empty) staff3)
              (make-staff-node staff2 empty
                               (make-staff-node staff3 empty empty)))
(check-expect (add-staff-bst
               (make-staff-node staff4
                                (make-staff-node
                                 staff2
                                 (make-staff-node staff1 empty empty)
                                 empty)
                                (make-staff-node staff4 empty empty)) staff3)
              (make-staff-node staff4
                               (make-staff-node
                                staff2
                                (make-staff-node staff1 empty empty)
                                (make-staff-node staff3 empty empty))
                               (make-staff-node staff4 empty empty)))

(define (add-staff-bst staff-bst staff-member)
  (cond
    [(empty? staff-bst) (make-staff-node staff-member empty empty)]
    [(> (staff-member-id (staff-node-staff staff-bst))
        (staff-member-id staff-member))
     (make-staff-node (staff-node-staff staff-bst)
                      (add-staff-bst (staff-node-left staff-bst) staff-member)
                      (staff-node-right staff-bst))]
    [else (make-staff-node (staff-node-staff staff-bst)
                           (staff-node-left staff-bst)
                           (add-staff-bst (staff-node-right staff-bst)
                                          staff-member))]))

;;Tests:
(check-expect (add-staff-bst empty staff5)
              (make-staff-node staff5 empty empty))
(check-expect
 (add-staff-bst
  (make-staff-node
   staff7
   (make-staff-node staff2 empty
                    (make-staff-node staff4
                                     (make-staff-node staff3 empty empty)
                                     (make-staff-node staff6 empty empty)))
   (make-staff-node staff8
                    (make-staff-node staff9 empty empty)
                    (make-staff-node staff10 empty empty))) staff5)
 (make-staff-node staff7
                  (make-staff-node staff2 empty
                                   (make-staff-node
                                    staff4
                                    (make-staff-node staff3 empty empty)
                                    (make-staff-node
                                     staff6
                                     (make-staff-node staff5 empty empty)
                                     empty)))
                  (make-staff-node staff8
                                   (make-staff-node staff9 empty empty)
                                   (make-staff-node staff10 empty empty))))
(check-expect (add-staff-bst
               (make-staff-node staff5
                                (make-staff-node staff3 empty empty)
                                (make-staff-node
                                 staff8
                                 (make-staff-node staff7 empty empty)
                                 (make-staff-node staff9 empty empty))) staff4)
              (make-staff-node staff5
                               (make-staff-node
                                staff3
                                empty
                                (make-staff-node staff4 empty empty))
                               (make-staff-node
                                staff8
                                (make-staff-node staff7 empty empty)
                                (make-staff-node staff9 empty empty))))



;;******************************************************************************



;;part (b)

;;(create-staff-bst-from-list lostaff) produces a Staff-BST that correponds
;;   to the list of Staff-Member lostaff

;;create-staff-bst-from-list: (listof Staff-Member) -> Staff-BST

;;requires: All Staff-Member in lostaff have a unique ID

;;Examples:
(check-expect (create-staff-bst-from-list (list staff4 staff6 staff1 staff3))
              (make-staff-node staff3
                               (make-staff-node staff1 empty empty)
                               (make-staff-node
                                staff6
                                (make-staff-node staff4 empty empty)
                                empty)))
(check-expect (create-staff-bst-from-list (list staff1 staff2 staff3))
              (make-staff-node staff3
                               (make-staff-node
                                staff2
                                (make-staff-node staff1 empty empty)
                                empty) empty))

(define (create-staff-bst-from-list lostaff)
  (cond
    [(empty? lostaff) empty]
    [else (add-staff-bst (create-staff-bst-from-list (rest lostaff))
                         (first lostaff))]))

;;Tests
(check-expect (create-staff-bst-from-list empty) empty)
(check-expect (create-staff-bst-from-list (list staff10 staff2 staff4 staff9
                                                staff1 staff5))
              (make-staff-node staff5
                               (make-staff-node
                                staff1 empty
                                (make-staff-node
                                 staff4
                                 (make-staff-node staff2 empty empty)
                                 empty))
                               (make-staff-node
                                staff9 empty
                                (make-staff-node staff10 empty empty))))
(check-expect (create-staff-bst-from-list (list staff8 staff2 staff5 staff7
                                                staff4 staff9 staff3 staff1
                                                staff6 staff10))
              (make-staff-node staff10
                               (make-staff-node
                                staff6
                                (make-staff-node
                                 staff1 empty
                                 (make-staff-node
                                  staff3
                                  (make-staff-node staff2 empty empty)
                                  (make-staff-node
                                   staff4 empty
                                   (make-staff-node staff5 empty empty))))
                                (make-staff-node
                                 staff9
                                 (make-staff-node
                                  staff7 empty
                                  (make-staff-node
                                   staff8 empty empty)) empty)) empty))



;;******************************************************************************



;;part (c)

;;(who-to-fire sal-list staff-bst cutoff) produces a (sorted) Staff-List of all 
;;   the Staff-Member in staff-bst whose salary is more than cutoff

;;who-to-fire: Sal-List Staff-BST Num -> Staff-List

;;requires: cutoff must be positive

;;Examples:
(check-expect (who-to-fire sal-list (create-staff-bst-from-list
                                     (list staff10 staff5 staff6 staff8
                                           staff4 staff7 staff9))
                           
                           100000)
              (list staff7 staff8 staff9 staff10))
(check-expect (who-to-fire given-sal-list
                           (create-staff-bst-from-list
                            (list staff10 staff5 staff6 staff8
                                  staff4 staff7 staff9))
                           100000)
              (list staff7 staff8 staff9))
(check-expect (who-to-fire sal-list (create-staff-bst-from-list
                                     (list staff2 staff1 staff3))
                           50000)
              (list staff3))

(define (who-to-fire sal-list staff-bst cutoff)
  (cond
    [(empty? staff-bst) empty]
    [(> (get-salary (staff-node-staff staff-bst) sal-list) cutoff)
     (append
      (who-to-fire sal-list (staff-node-left staff-bst) cutoff)
      (list (staff-node-staff staff-bst))
      (who-to-fire sal-list (staff-node-right staff-bst) cutoff))]
    [else (append
           (who-to-fire sal-list (staff-node-left staff-bst) cutoff)
           (who-to-fire sal-list (staff-node-right staff-bst) cutoff))]))

;;Tests:
(check-expect (who-to-fire given-sal-list
                           (create-staff-bst-from-list
                            (list staff5 staff6 staff10)) .01)
              empty)
(check-expect (who-to-fire sal-list
                           (create-staff-bst-from-list
                            (list staff5 staff6 staff10)) .01)
              (list staff5 staff6 staff10))
(check-expect (who-to-fire sal-list
                           (create-staff-bst-from-list
                            (list staff1 staff2 staff3 staff4 staff5
                                  staff6 staff7 staff8 staff9 staff10)) 250000)
              (list staff10))



;;(get-salary staff-member sal-list) produces the salary, base and bonus, of
;;   staff-member by looking for their ID in sal-list, if ID not found salary=0;

;;get-salary: Staff-Member Sal-List -> Nat

;;Examples:
(check-expect (get-salary staff10 sal-list) 600500)
(check-expect (get-salary staff6 sal-list) 68500)
(check-expect (get-salary staff5 given-sal-list) 0)

(define (get-salary staff-member sal-list)
  (cond
    [(empty? sal-list) 0]
    [(= (staff-member-id staff-member) (salary-staff-id (first sal-list)))
     (+ (salary-base (first sal-list)) (salary-bonus (first sal-list)))]
    [else (get-salary staff-member (rest sal-list))]))

;;Tests:
(check-expect (get-salary staff6 given-sal-list) 0)
(check-expect (get-salary staff5 sal-list) 93100)



;;******************************************************************************



;;part (d)

;;(remove-from-bst staff-bst id) produces a new staff-bst with the staff-node
;;   containing the staff-member with ID 'id' removed, if no staff-member has
;;   ID 'id', produces the same staff-bst as input

;;remove-from-bst: Staff-BST Nat -> Staff-BST

;;Examples:
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff1 staff2 staff7 staff8 staff10
                                      staff9 staff3)) 1)
              (create-staff-bst-from-list
               (list staff2 staff7 staff8 staff10 staff9 staff3)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff1 staff2 staff7 staff8 staff10 staff9
                                      staff3)) 8)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff10 staff9 staff3)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff1 staff2 staff7 staff8 staff10 staff9
                                      staff3)) 3)
              (create-staff-bst-from-list
               (list staff1 staff2 staff8 staff10 staff9 staff7)))
(check-expect (remove-from-bst empty 1)
              empty)

(define (remove-from-bst staff-bst id)
  (cond
    [(number? (get-id-node staff-bst id)) staff-bst]
    [(and (not (empty? (staff-node-left (get-id-node staff-bst id))))
          (not (empty? (staff-node-right (get-id-node staff-bst id)))))
     (make-staff-node (staff-node-staff (change-node-successor staff-bst id))
                      (remove-from-bst
                       (staff-node-left
                        (change-node-successor staff-bst id))
                       (get-successor-id (get-id-node staff-bst id)))
                      (remove-from-bst
                       (staff-node-right
                        (change-node-successor staff-bst id))
                       (get-successor-id (get-id-node staff-bst id))))]
    [(and (empty? (staff-node-left (get-id-node staff-bst id)))
          (empty? (staff-node-right (get-id-node staff-bst id))))
     (remove-node staff-bst id)]
    [else (change-node-child staff-bst id)]))

;;Tests:
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff1 staff2 staff7 staff8 staff10
                                      staff9 staff3)) 9)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff10 staff3)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff1 staff2 staff7 staff8 staff10
                                      staff9 staff3)) 11)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff10 staff9 staff3)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff10 staff2 staff5 staff3 staff9
                                      staff6 staff7)) 7)
              (create-staff-bst-from-list
               (list staff4 staff10 staff2 staff5 staff3 staff6 staff9)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff10 staff2 staff5 staff3 staff9
                                      staff6 staff7)) 3)
              (create-staff-bst-from-list
               (list  staff10 staff2 staff5 staff4 staff9 staff6 staff7)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 9)
              (create-staff-bst-from-list
               (list staff4 staff7 staff2 staff1 staff10 staff3 staff5 staff8
                     staff6)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 2)
              (create-staff-bst-from-list
               (list staff4 staff7 staff9 staff1 staff10 staff3 staff5 staff8
                     staff6)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 5)
              (create-staff-bst-from-list
               (list staff4 staff7 staff2 staff9 staff1 staff10 staff3 staff8
                     staff6)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 10)
              (create-staff-bst-from-list
               (list staff4 staff7 staff2 staff9 staff1 staff3 staff5 staff8
                     staff6)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 6)
              (create-staff-bst-from-list
               (list staff4  staff2 staff9 staff1 staff10 staff3 staff5 staff8
                     staff7)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 8)
              (create-staff-bst-from-list
               (list staff4 staff7 staff2  staff1 staff10 staff3 staff5 staff9
                     staff6)))
(check-expect (remove-from-bst (create-staff-bst-from-list
                                (list staff4 staff7 staff2 staff9 staff1 staff10
                                      staff3 staff5 staff8 staff6)) 3)
              (create-staff-bst-from-list
               (list  staff7 staff2 staff9 staff1 staff10 staff4 staff5 staff8
                      staff6)))



;;(get-id-node staff-bst id) produces the staff-node that corresponds to the
;;   staff ID 'id', if ID not found produces 0 

;;get-id-node: Staff-BST Nat -> (anyof Staff-Node Num)

;;Examples:
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 1)
              (make-staff-node staff1 empty empty))
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 2)
              (make-staff-node staff2
                               (make-staff-node staff1 empty empty) empty))
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 3)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff10 staff9 staff3)))

(define (get-id-node staff-bst id)
  (cond
    [(empty? staff-bst) 0]
    [(= id (staff-member-id (staff-node-staff staff-bst))) staff-bst]
    [(> id (staff-member-id (staff-node-staff staff-bst)))
     (get-id-node (staff-node-right staff-bst) id)]
    [else (get-id-node (staff-node-left staff-bst) id)]))

;;Tests:
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 9)
              (make-staff-node staff9
                               (make-staff-node staff8
                                                (make-staff-node staff7 empty
                                                                 empty)
                                                empty)
                               (make-staff-node staff10 empty empty)))
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 8)
              (make-staff-node staff8
                               (make-staff-node staff7 empty empty)
                               empty))
(check-expect (get-id-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3)) 11)
              0)



;;(remove-node staff-bst id) removes the Staff-Node that id corresponds to from
;;   staff-bst

;;remove-node: Staff-BST Nat -> Staff-BST

;;requires: id corresponds to a staff-node that is in staff-bst and has no
;;   children (ie it's a leaf)

;;Examples:
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3))
                           1)
              (create-staff-bst-from-list
               (list staff2 staff7 staff8 staff10 staff9 staff3)))
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3))
                           7)
              (create-staff-bst-from-list
               (list staff1 staff2 staff8 staff10 staff9 staff3)))
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff1 staff2 staff7 staff8 staff10 staff9
                                  staff3))
                           10)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff9 staff3)))

(define (remove-node staff-bst id)
  (cond
    [(> id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (staff-node-left staff-bst)
      (remove-node (staff-node-right staff-bst) id))]
    [(< id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (remove-node (staff-node-left staff-bst) id)
      (staff-node-right staff-bst))]
    [else empty]))

;;Tests:
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff4 staff8 staff2 staff5 staff3 staff9
                                  staff6 staff7))
                           2)
              (create-staff-bst-from-list
               (list staff4 staff8 staff5 staff3 staff9 staff6 staff7)))
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff4 staff8 staff2 staff5 staff3 staff9
                                  staff6 staff7))
                           4)
              (create-staff-bst-from-list
               (list staff8 staff2 staff5 staff3 staff9 staff6 staff7)))
(check-expect (remove-node (create-staff-bst-from-list
                            (list staff4 staff8 staff2 staff5 staff3 staff9
                                  staff6 staff7))
                           8)
              (create-staff-bst-from-list
               (list staff4 staff2 staff5 staff3 staff9 staff6 staff7)))



;;(change-node-child staff-bst id) changes the staff-node in staff-bst that
;;   id corresponds to into its child

;;change-node-child: Staff-BST Nat -> Staff-BST

;;requires: id corresponds to a staff-node that is in staff-bst and has one
;;   child

;;Examples:
(check-expect (change-node-child (create-staff-bst-from-list
                                  (list staff1 staff2 staff7 staff8 staff10
                                        staff9 staff3))
                                 2)
              (create-staff-bst-from-list
               (list staff1 staff7 staff8 staff10 staff9 staff3)))
(check-expect (change-node-child (create-staff-bst-from-list
                                  (list staff1 staff2 staff7 staff8 staff10
                                        staff9 staff3))
                                 8)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff10 staff9 staff3)))
(check-expect (change-node-child (create-staff-bst-from-list
                                  (list staff4 staff8 staff2 staff5 staff3
                                        staff9 staff6 staff7))
                                 5)
              (create-staff-bst-from-list
               (list staff4 staff8 staff2 staff3 staff9 staff6 staff7)))

(define (change-node-child staff-bst id)
  (cond
    [(> id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (staff-node-left staff-bst)
      (change-node-child (staff-node-right staff-bst) id))]
    [(< id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (change-node-child
                                    (staff-node-left staff-bst) id)
      (staff-node-right staff-bst))]
    [(empty? (staff-node-left staff-bst)) (staff-node-right staff-bst)]
    [(empty? (staff-node-right staff-bst)) (staff-node-left staff-bst)]))

;;Tests:
(check-expect (change-node-child (create-staff-bst-from-list
                                  (list staff4 staff10 staff2 staff5 staff3
                                        staff9 staff6 staff7))
                                 6)
              (create-staff-bst-from-list
               (list staff4 staff10 staff2 staff5 staff3 staff9 staff7)))
(check-expect (change-node-child (create-staff-bst-from-list
                                  (list staff4 staff10 staff2 staff5 staff3
                                        staff9 staff6 staff7))
                                 9)
              (create-staff-bst-from-list
               (list staff4 staff10 staff2 staff5 staff3 staff6 staff7)))



;;(change-node-successor staff-bst id) changes the staff-node in staff-bst
;;   that id corresonds to into its successor (a successor is the 
;;   staff-member with the minimum-id in the right node of the predecessor)

;;change-node-successor: Staff-BST Nat -> Staff-BST

;;requires: id corresponds to a staff-node that is in staff-bst and has 2
;;   children

;;Examples:
(check-expect (change-node-successor (create-staff-bst-from-list
                                      (list staff1 staff2 staff7 staff8 staff10
                                            staff9 staff3))
                                     3)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff10 staff9 staff7)))
(check-expect (change-node-successor (create-staff-bst-from-list
                                      (list staff1 staff2 staff7 staff8 staff10
                                            staff9 staff3))
                                     9)
              (create-staff-bst-from-list
               (list staff1 staff2 staff7 staff8 staff10 staff10 staff3)))

(define (change-node-successor staff-bst id)
  (cond
    [(> id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (staff-node-left staff-bst)
      (change-node-successor (staff-node-right staff-bst) id))]
    [(< id (staff-member-id (staff-node-staff staff-bst)))
     (make-staff-node
      (staff-node-staff staff-bst) (change-node-successor
                                    (staff-node-left staff-bst) id)
      (staff-node-right staff-bst))]
    [else (make-staff-node
           (staff-node-staff (get-id-node staff-bst
                                          (get-successor-id staff-bst)))
           (staff-node-left staff-bst)
           (staff-node-right staff-bst))]))

;;Tests:
(check-expect (change-node-successor (create-staff-bst-from-list
                                      (list staff4 staff10 staff2 staff5 staff3
                                            staff9 staff6 staff7))
                                     3)
              (create-staff-bst-from-list
               (list staff4 staff10 staff2 staff5 staff4 staff9 staff6 staff7)))
(check-expect (change-node-successor (create-staff-bst-from-list
                                      (list staff4 staff10 staff2 staff5 staff3
                                            staff9 staff6 staff7))
                                     7)
              (create-staff-bst-from-list
               (list staff4 staff10 staff2 staff5 staff3 staff9 staff6 staff9)))



;;(get-successor-id staff-bst) produces the id of the successor of the root 
;;   staff-member in staff-bst

;;get-successor-id: Staff-BST -> Nat

;;requires: staff-bst has 2 children

;;Examples:
(check-expect (get-successor-id (create-staff-bst-from-list
                                 (list staff1 staff2 staff7 staff8 staff10
                                       staff9 staff3)))
              7)
(check-expect (get-successor-id (create-staff-bst-from-list
                                 (list staff7 staff9 staff10 staff8)))
              9)
(check-expect (get-successor-id (create-staff-bst-from-list
                                 (list staff2 staff4 staff5 staff3)))
              4)

(define (get-successor-id staff-bst)
  (get-min-id (staff-node-right staff-bst)))

;;Tests:
(check-expect (get-successor-id (create-staff-bst-from-list
                                 (list staff2 staff4 staff5 staff3 staff6
                                       staff10 staff9 staff7)))
              9)
(check-expect (get-successor-id (create-staff-bst-from-list
                                 (list staff7 staff8 staff10 staff9)))
              10)



;;(get-min-id staff-bst) prodcues the minimum staff-id in staff-bst

;;get-min-id: Staff-BST -> Nat

;;requires: staff-bst has at least one staff-node

;;Examples:
(check-expect (get-min-id (create-staff-bst-from-list
                           (list staff7 staff8 staff10 staff9)))
              7)
(check-expect (get-min-id (create-staff-bst-from-list
                           (list  staff4 staff5 staff3 staff6 staff2 staff10
                                  staff9 staff7)))
              2)
(check-expect (get-min-id (create-staff-bst-from-list
                           (list  staff4 staff5 staff3 staff6 staff10
                                  staff9 staff7)))
              3)

(define (get-min-id staff-bst)
  (cond
    [(empty? (staff-node-left staff-bst)) (staff-member-id
                                           (staff-node-staff staff-bst))]
    [else (get-min-id (staff-node-left staff-bst))]))

;;Tests:
(check-expect (get-min-id (create-staff-bst-from-list
                           (list staff10)))
              10)
(check-expect (get-min-id (create-staff-bst-from-list
                           (list staff1 staff10)))
              1)
(check-expect (get-min-id (create-staff-bst-from-list
                           (list staff1 staff2 staff10)))
              1)












