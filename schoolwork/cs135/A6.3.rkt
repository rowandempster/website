;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 06, Problem 3
;;**********************************************

;;Data definitions:

;; A Matrix is a (listof (listof Num))
;; Requires: Length of all (listof Num) be the same


;;******************************************************************************


;; part (a)

;;(matrix-row matrix row-num) produces the row in maxtrix that row-num
;;   corresponds to

;; matrix-row: Matrix Nat -> (listof Num)

;; requires: matrix is non-empty
;;                row-num < (length matrix)

;;Examples:
(check-expect (matrix-row (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4)) 1)
              (list 4 5 2 3))
(check-expect (matrix-row (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4)) 0)
              (list 5 8 4 5))
(check-expect (matrix-row (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4)) 2)
              (list 4 5 2 4))

(define (matrix-row matrix row-num)
  (cond
    [(= row-num 0) (first matrix)]
    [else (matrix-row (rest matrix) (sub1 row-num))]))

;;Tests:
(check-expect (matrix-row (list (list 1)
                                (list -1)
                                (list -1000)
                                (list 5)
                                (list 7)) 3)
              (list 5))
(check-expect (matrix-row (list (list 00 00 00 0)
                                (list 11 11 11 1 )
                                (list 22 2 22)) 1)
              (list 11 11 11 1 ))
(check-expect (matrix-row (list (list 1 2)
                                (list 2 3)
                                (list 4 5)
                                (list empty)) 3)
              (list empty))



;;******************************************************************************



;; part (b)

;;(matrix-col-count-row matrix current-row col-num col-counter) produces
;;   the row in matrix that correspond to col-num (current-row and col-counter
;;   are counters)

;;matrix-col-count-row: Matrix (listof Num) Nat Nat -> (listof Num)

;; requires: matrix is non-empty
;;                row-num < (length (first matrix))

;;Examples:
(check-expect (matrix-col-count-row (list (list 5 8 4 5)
                                          (list 4 5 2 3)
                                          (list 4 5 2 4))
                                    (list 5 8 4 5)
                                    0
                                    0)
              (list 5 4 4))
(check-expect (matrix-col-count-row (list (list 5 8 4 5)
                                          (list 4 5 2 3)
                                          (list 4 5 2 4))
                                    (list 5 8 4 5)
                                    1
                                    1)
              (list 8 5 5))

(check-expect (matrix-col-count-row (list (list 5 8 4 5)
                                          (list 4 5 2 3)
                                          (list 4 5 2 4))
                                    (list 5 8 4 5)
                                    3
                                    3)
              (list 5 3 4))

(define (matrix-col-count-row matrix current-row col-num col-counter)
  (cond
    [(empty? (rest matrix)) (cons (pick-element current-row col-num) empty)]
    [(= col-counter 0) (cons (first current-row)
                             (matrix-col-count-row
                              (rest matrix)
                              (first (rest matrix)) col-num col-num))]
    [else (matrix-col-count-row matrix
                                (rest current-row) col-num
                                (sub1 col-counter))]))

;;Tests
(check-expect (matrix-col-count-row (list (list 1 1 1)
                                          (list 2 2 2)
                                          (list 3 3 3))
                                    (list 1 1 1)
                                    2
                                    2)
              (list 1 2 3))
(check-expect (matrix-col-count-row (list (list 0)
                                          (list 0))
                                    (list 0)
                                    0
                                    0)
              (list 0 0))
(check-expect (matrix-col-count-row (list (list 1 3 8 9 3 5 24 53))
                                    (list 1 3 8 9 3 5 24 53)
                                    4
                                    4)
              (list 3))



;;(pick-element row col) produces the element in row that col corresponds to

;;pick-element: (listof Num) Nat -> Num

;;requires: col < (length row)

;;Examples:
(check-expect (pick-element (list -1 3 2.33) 2) 2.33)
(check-expect (pick-element (list -1 3 2.33) 0) -1)
(check-expect (pick-element (list 0) 0) 0)

(define (pick-element row col)
  (cond
    [(= col 0) (first row)]
    [else (pick-element (rest row) (sub1 col))]))

;;Tests:
(check-expect (pick-element (list -1 3 2.33 6 2 4 9.64) 4) 2)
(check-expect (pick-element (list 0 0 0 1) 3) 1)
(check-expect (pick-element (list 0 1 2 3 4 5 10) 6) 10)



;;(matrix-col matrix col-num) produces the column in maxtrix that col-num
;;   corresponds to

;; matrix-col: Matrix Nat -> (listof Num)

;; requires: matrix is non-empty
;;           col-num < (length (first matrix))

;;Examples:
(check-expect (matrix-col (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4))
                          0)
              (list 5 4 4))
(check-expect (matrix-col (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4))
                          1)
              (list 8 5 5))
(check-expect (matrix-col (list
                           (list 5 8 4 5)
                           (list 4 5 2 3)
                           (list 4 5 2 4))
                          2)
              (list 4 2 2))

(define (matrix-col matrix col-num)
  (matrix-col-count-row matrix (first matrix) col-num col-num))

;;Tests:
(check-expect (matrix-col (list
                           (list 1)
                           (list 2)
                           (list 3))
                          0)
              (list 1 2 3))
(check-expect (matrix-col (list
                           (list 1 7 8 2 5 8 2)
                           )
                          5)
              (list 8))
(check-expect (matrix-col (list
                           (list 1 2 3 4)
                           (list 4 3 2 1))
                          3)
              (list 4 1))



;;******************************************************************************



;; part (c)

;;(get-element matrix row col) produces the element of matrix in row "row"
;;   and col "col"

;;get-element: Matrix Nat Nat -> Num

;; requires: matrix is non-empty
;;           row < (length matrix)
;;           col < (length (first matrix))

;;Examples:
(check-expect (get-element (list (list 1 2 3 4)
                                 (list 4 3 2 1)
                                 (list 2 3 1 4))
                           2 3)
              4)
(check-expect (get-element (list (list 1 2 3 4)
                                 (list 4 3 2 1)
                                 (list 2 3 1 4))
                           1 0)
              4)
(check-expect (get-element (list (list 1 2 3 4)
                                 (list 4 3 2 1)
                                 (list 2 3 1 4))
                           0 2)
              3)

(define (get-element matrix row col)
  (pick-element (matrix-row matrix row) col))

;;Tests:
(check-expect (get-element (list (list 1)
                                 (list 1)
                                 (list 2))
                           1 0)
              1)
(check-expect (get-element (list (list 1)
                                 (list 1)
                                 (list 2))
                           2 0)
              2)
(check-expect (get-element (list (list 1 4 5 2 5 2))
                           0 3)
              2)
(check-expect (get-element (list (list 1 4 5 2 5 2)
                                 (list 1 4 2 4 5 2)
                                 (list 1 34 -2 .34 5 2))
                           2 3)
              .34)



;;******************************************************************************



;; part (d)

;;(add-rows row1 row2 current-element end-element) produces a row whos elements
;;   are the sum of each respective element in row1 and row2

;;add-rows: (listof Num) (listof Num) Nat Nat -> (listof Num)

;;requires: row1 and row2 are not empty, current-element starts at 0,
;;   end-element = (length row1)

;;Examples:
(check-expect (add-rows (list 1 1 1) (list 1 1 1) 0 3) (list 2 2 2))
(check-expect (add-rows (list 1) (list 1) 0 1) (list 2))
(check-expect (add-rows (list 99 99 1 1 50) (list 1 1 99 99 51) 0 5)
              (list 100 100 100 100 101))

(define (add-rows row1 row2 current-element end-element)
  (cond
    [(= current-element end-element) empty]
    [else (cons (+ (first row1) (first row2))
                (add-rows (rest row1) (rest row2)
                          (add1 current-element) end-element))]))

;;Tests:
(check-expect (add-rows (list 99 99 1 1 50) (list 1 1 99 99 51) 0 5)
              (list 100 100 100 100 101))
(check-expect (add-rows (list 0 0 0 0) (list 4 5 2 6) 0 4)
              (list 4 5 2 6))
(check-expect (add-rows (list 5 2 9 5 1 9) (list 0 0 0 0 0 0) 0 6)
              (list 5 2 9 5 1 9))



;;(create-rows matrix1 matrix2 current-row end-row) produces the matrix created
;;   by adding matrix1 and matrix2, starting at current-row and ending at
;;   end-row

;;create-rows: Matrix Matrix Nat Nat -> Matrix

;;requires: current-row is initally 0 and end-row is initial (length matrix1)
;;           neither matrix can be empty

;;Examples
(check-expect (create-rows (list
                            (list 1 2 3) 
                            (list 3 2 1)
                            (list 2 1 3))
                           (list
                            (list 4 5 6)
                            (list 6 5 4)
                            (list 5 4 6))
                           0 3)
              (list
               (list 5 7 9)
               (list 9 7 5)
               (list 7 5 9)))
(check-expect (create-rows (list
                            (list 0 0 0) 
                            (list 2 2 2))
                           (list
                            (list 2 2 2)
                            (list 0 0 0))
                           0 2)
              (list
               (list 2 2 2)
               (list 2 2 2)))
(check-expect (create-rows (list
                            (list 1 1 1) 
                            (list 0 0 0)
                            (list 2 2 2))
                           (list
                            (list 1 1 1)
                            (list 2 2 2)
                            (list 0 0 0))
                           0 3)
              (list
               (list 2 2 2)
               (list 2 2 2)
               (list 2 2 2)))

(define (create-rows matrix1 matrix2 current-row end-row)
  (cond
    [(= current-row end-row) empty]
    [else (cons (add-rows (first matrix1) (first matrix2) 0
                          (length (first matrix1)))
                (create-rows (rest matrix1) (rest matrix2)
                             (add1 current-row) end-row))]))

;;Tests:
(check-expect (create-rows (list
                            (list 1) 
                            (list 99)
                            (list 0))
                           (list
                            (list 99)
                            (list 1)
                            (list 100))
                           0 3)
              (list
               (list 100)
               (list 100)
               (list 100)))
(check-expect (create-rows (list
                            (list 0) 
                            (list 0)
                            (list 0))
                           (list
                            (list 1)
                            (list 1)
                            (list 1))
                           0 3)
              (list
               (list 1)
               (list 1)
               (list 1)))
(check-expect (create-rows (list
                            (list -4 3 -5 2 -8 -9))
                           (list
                            (list 8 9 -9 2 4 -9))
                           0 1)
              (list
               (list 4 12 -14 4 -4 -18)))



;;(matrix-add matrix1 matrix2) produces a matrix with elements equal to the
;;   sum of the respective in matrix1 and matrix2

;;matrix-add: Matrix Matrix -> Matrix

;; requires: (length matrix1) = (length matrix2)
;;           (length each row of matrix1) = (length each row of matrix2)
;;           neither matrix can be empty

;;Examples:
(check-expect (matrix-add (list
                           (list 1 4 2 7)
                           (list 2 8 4 5))
                          (list
                           (list 4 1 9 5)
                           (list 5 2 9 5)))
              (list
               (list 5 5 11 12)
               (list 7 10 13 10)))
(check-expect (matrix-add (list
                           (list 1 4 2 7)
                           (list 2 8 4 5)
                           (list 1 2 3 4))
                          (list
                           (list 4 1 9 5)
                           (list 5 2 9 5)
                           (list 0 0 0 0)))
              (list
               (list 5 5 11 12)
               (list 7 10 13 10)
               (list 1 2 3 4)))
(check-expect (matrix-add (list
                           (list 1 4 2 7)
                           (list 2 8 4 5)
                           (list 0 0 0 0))
                          (list
                           (list 4 1 9 5)
                           (list 5 2 9 5)
                           (list 0.1 0.1 0.1 0)))
              (list
               (list 5 5 11 12)
               (list 7 10 13 10)
               (list .1 .1 .1 0)))

(define (matrix-add matrix1 matrix2)
  (create-rows matrix1 matrix2 0 (length matrix1)))

;;Tests:
(check-expect (matrix-add (list
                           (list 0 0 0)
                           (list 0 1 0)
                           (list 0 0 0))
                          (list
                           (list 1 1 1)
                           (list 1 0 1)
                           (list 1 1 1)))
              (list
               (list 1 1 1)
               (list 1 1 1)
               (list 1 1 1)))
(check-expect (matrix-add (list
                           (list 5 5 5)
                           (list -5 -5 -5)
                           (list 100 100 100))
                          (list
                           (list 95 95 95)
                           (list 105 105 105)
                           (list 0 0 1)))
              (list
               (list 100 100 100)
               (list 100 100 100)
               (list 100 100 101)))
(check-expect (matrix-add (list
                           (list 5 5 5 10 10 0 0))
                          (list
                           (list 95 95 95 90 90 100 101)))
              (list
               (list 100 100 100 100 100 100 101)))



;;******************************************************************************



;;part (e)

;; (dot-product lon1 lon2) computes the dot product of lon1 and lon2

;; dot-product: (listof Num) (listof Num) -> Num

;; requires: lon1 and lon2 are the same length

;;Examples:
(check-expect (dot-product empty empty) 0)
(check-expect (dot-product (list 2) (list 3)) 6)
(check-expect (dot-product (list 4 5) (list 2 3)) 23)

(define (dot-product lon1 lon2)
  (cond
    [(or (empty? lon1) (empty? lon2)) 0]
    [else (+ (* (first lon1) (first lon2))
             (dot-product (rest lon1) (rest lon2)))]))
;;Tests:
(check-expect (dot-product (list 0 0 0 0 1) (list 58 24 12 23 101)) 101)
(check-expect (dot-product (list 0 0 0 0 2) (list 58 24 12 23 101)) 202)
(check-expect (dot-product (list 1 2 3) (list 3 3/2 1)) 9)
(check-expect (dot-product (list -1 2 -3 .1) (list 3 3/2 1 30)) 0)


;;(create-a-mult-row row matrix current-col current-col-num end-col-num)
;;   produces a row with each of its elements equal to the dot product of
;;   row and each of the respective columns of matrix

;;create-a-mult-row: (listof Num) Matrix (listofNum) Nat Nat -> (listof Num)

;;requires: (length row) = (length current-col) (for dot product operation)
;;          (length row) = (length matrix) (for dot product operations)
;;          current-col starts at (matrix-col matrix 0)
;;          current-col-num starts at 0
;;          end-col-num = (length (first matrix))
;;          row matrix and current-col must be non-empty

;;Examples:
(check-expect (create-a-mult-row (list 0 3 5)
                                 (list (list 3 4)
                                       (list 3 -2)
                                       (list 4 -2))
                                 (list 3 3 4)
                                 0 2) (list 29 -16))
(check-expect (create-a-mult-row (list 2 2 2 0)
                                 (list (list 1 2)
                                       (list 2 1)
                                       (list 0 0)
                                       (list 1 1))
                                 (list 1 2 0 1)
                                 0 2) (list 6 6))
(check-expect (create-a-mult-row (list 1 1)
                                 (list (list -100 2)
                                       (list 900 1))
                                 (list -100 900)
                                 0 2) (list 800 3))

(define (create-a-mult-row row matrix current-col current-col-num end-col-num)
  (cond
    [(= current-col-num end-col-num) empty]
    [else (cons (dot-product row (matrix-col matrix current-col-num))
                (create-a-mult-row row matrix
                                   (matrix-col matrix current-col-num)
                                   (add1 current-col-num) end-col-num))]))
;;Tests:
(check-expect (create-a-mult-row (list 0 0 0 0 0 1)
                                 (list (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 2 3 4))
                                 (list 1 1 1 1 1 1)
                                 0 4) (list 1 2 3 4))
(check-expect (create-a-mult-row (list 0 0 0 0 1 1)
                                 (list (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 2 3 4))
                                 (list 1 1 1 1 1 1)
                                 0 4) (list 2 3 4 5))
(check-expect (create-a-mult-row (list 1 0 0 0 1 1)
                                 (list (list 2 2 2 2)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 1 1 1)
                                       (list 1 2 3 4))
                                 (list 1 1 1 1 1 1)
                                 0 4) (list 4 5 6 7))



;;(create-mult-rows matrix1 matrix2 current-row end-row) produces a matrix that
;;   is the result of multiplying matrix1 and matrix2, starting at current-row
;;   and ending at end-row

;;create-mult-rows: Matrix Matrix Nat Nat -> Matrix

;;requires: (length each row of matrix1) = (length matrix2)
;;          neither matrix is empty
;;          current-row starts at 0
;;          end-row = (length matrix1)

;;Examples:
(check-expect (create-mult-rows (list
                                 (list 0 3 5)
                                 (list 5 5 2))
                                (list
                                 (list 3 4)
                                 (list 3 -2)
                                 (list 4 -2)) 0 2)
              (list (list 29 -16)
                    (list 38 6)))
(check-expect (create-mult-rows (list
                                 (list 1 2 3)
                                 (list 3 2 1))
                                (list
                                 (list 1 1 1 1 1)
                                 (list 2 2 2 2 2)
                                 (list -3 -3 -3 -3 -3)) 0 2)
              (list (list -4 -4 -4 -4 -4)
                    (list 4 4 4 4 4)))
(check-expect (create-mult-rows (list
                                 (list 1 2 3)
                                 (list 3 2 1))
                                (list
                                 (list 0 0 0 0 0)
                                 (list 1 2 3 4 5)
                                 (list -3 -3 -3 -3 -3)) 0 2)
              (list (list -7 -5 -3 -1 1)
                    (list -1 1 3 5 7)))

(define (create-mult-rows matrix1 matrix2 current-row end-row)
  (cond
    [(= current-row end-row) empty]
    [else (cons (create-a-mult-row (first matrix1) matrix2
                                   (matrix-col matrix2 0) 0
                                   (length (first matrix2)))
                (create-mult-rows (rest matrix1) matrix2
                                  (add1 current-row) end-row))]))
;;Tests:
(check-expect (create-mult-rows (list
                                 (list 0 -3 -2)
                                 (list 4 -1 1)
                                 (list 3 5 2))
                                (list
                                 (list 6 7)
                                 (list 4 8)
                                 (list -3 3)) 0 3)
              (list (list -6 -30)
                    (list 17 23)
                    (list 32 67)))
(check-expect (create-mult-rows (list
                                 (list -4 6)
                                 (list 2 1)
                                 (list 0 3)
                                 (list 4 5))
                                (list
                                 (list 7 6 -1)
                                 (list 2 8 9)) 0 4)
              (list (list -16 24 58)
                    (list 16 20 7)
                    (list 6 24 27)
                    (list 38 64 41)))



;;(matrix-multiply matrix1 matrix2) produces a matrix that is the result of
;;   multiplying matrix1 and matrix2

;; matrix-multiply: Matrix Matrix -> Matrix

;; requires:  (length each row of matrix1) = (length matrix2)

;;Examples:
(check-expect (matrix-multiply (list
                                (list 0 -1 1 2))
                               (list
                                (list -2)
                                (list 0)
                                (list 3)
                                (list 4)))
              (list (list 11)))
(check-expect (matrix-multiply (list
                                (list 0 -1 1 2))
                               (list
                                (list -2)
                                (list 0)
                                (list 3)
                                (list 4)))
              (list (list 11)))
(check-expect (matrix-multiply empty
                               (list
                                (list -2)
                                (list 0)
                                (list 3)
                                (list 4)))
              empty)

(define (matrix-multiply matrix1 matrix2)
  (cond
    [(or (empty? matrix1) (empty? matrix2)) empty]
    [else (create-mult-rows matrix1 matrix2 0 (length matrix1))]))

;;Tests:
(check-expect (matrix-multiply (list
                                (list 0 -1 1 2))
                               empty)
              empty)
(check-expect (matrix-multiply (list
                                (list 3 4 5)
                                (list 6 -4 -3))
                               (list
                                (list 0 3 1 2)
                                (list 6 -2 -1 4)
                                (list 5 7 8 9)))
              (list
               (list 49 36 39 67)
               (list -39 5 -14 -31)))
(check-expect (matrix-multiply (list
                                (list 3 4 5)
                                (list 6 -4 -3))
                               (list
                                (list 0 3 1 2)
                                (list 6 -2 -1 4)
                                (list 5 7 8 9)))
              (list
               (list 49 36 39 67)
               (list -39 5 -14 -31)))
(check-expect (matrix-multiply (list
                                (list 3 -1 0)
                                (list -2 4 1)
                                (list 2 5 6))
                               (list
                                (list 3 -1 0)
                                (list -4 4 1)
                                (list -3 5 6)))
              (list
               (list 13 -7 -1)
               (list -25 23 10)
               (list -32 48 41)))
(check-expect (matrix-multiply (list
                                (list 0 0)
                                (list 0 0))
                               (list               ;;<<-- "Zero" multiplication
                                (list 2 5 2 8 -4)
                                (list 1 4 2 5 3)))
              (list
               (list 0 0 0 0 0)
               (list 0 0 0 0 0)))
(check-expect (matrix-multiply (list
                                (list 1 0)
                                (list 0 1))
                               (list               ;;<<-- "One" multuplication
                                (list 2 5 2 8 -4)
                                (list 1 4 2 5 3)))
              (list
              (list 2 5 2 8 -4)
              (list 1 4 2 5 3)))
(check-expect (matrix-multiply (list
                                (list 0 1)
                                (list 1 0))
                               (list
                                (list 2 5 2 8 -4)
                                (list 1 4 2 5 3)))
              (list
              (list 1 4 2 5 3)
              (list 2 5 2 8 -4)))




























