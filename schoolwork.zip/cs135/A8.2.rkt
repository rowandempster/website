;;**********************************************
;;Rowan Dempster (20635120)
;;CS 135 Fall 2015
;;Assignment 08, Problem 3
;;**********************************************



;;part(a)

(define-struct email (staff-id recipients word-count reply))
;;An Email is a (make-email Nat (listof Nat) Nat Reply)
;;requires: the staff ids in 'recipients' must be unique

;;A Reply is a (listof Email)
;;requires: Reply only contains emails that are direct responses to
;;   the email structure it is a part of



;;******************************************************************************



;;Examples (put here becuase they need (make-email):
(define email0 (make-email 1 (list 2 3) 0 empty))
(define email10 (make-email 5 (list 4 7) 30 empty))
(define email9 (make-email 8 (list 4 7) 30 empty))
(define email8 (make-email 4 (list 1 5) 30 (list email0 email10)))
(define email7 (make-email 1 (list 2 3) 5 empty))
(define email6 (make-email 2 (list 1 4 5) 10 (list email7)))
(define email5 (make-email 3 (list 2 6 7) 15 (list email6)))
(define email4 (make-email 1 (list 2 3 4 5 6 7) 20 empty))
(define email3 (make-email 2 (list 3 5 6) 25 empty))
(define email2 (make-email 3 (list 4 8 5) 30 (list email8 email9 email10)))
(define email1 (make-email 1 (list 3 2 1) 35 (list email2 email3 email4)))



;;******************************************************************************



;;part (b)

;;(total-word-count original-email) produces the sum of the word count of
;;    original-email and all of its replies

;;total-word-count: Email -> Nat

;;Examples:
(check-expect (total-word-count email1) 230)
(check-expect (total-word-count email6) 15)
(check-expect (total-word-count email4) 20)

(define (total-word-count original-email)
  (local
    ;;(get-reply-word-count reply) procudes the sum of all the word counts an
    ;;   emails replies, or 0 if it has no replies
    ;;get-reply-word-count: Reply -> Nat
    [(define (get-reply-word-count reply)
       (cond
         [(empty? reply) 0]
         [else (+ (email-word-count (first reply))
                  (get-reply-word-count (rest reply))
                  (get-reply-word-count (email-reply (first reply))))]))]
    (+ (email-word-count original-email)
       (get-reply-word-count (email-reply original-email)))))

;;Tests:
(check-expect (total-word-count email0) 0)
(check-expect (total-word-count email5) 30)
(check-expect (total-word-count email2) 150)



;;******************************************************************************



;;part (c)

;;(unique-email-senders email-list) produces a list containing the id's of all
;;   unique staff members in email-list

;;unique-email-senders: (listof Email) -> (listof Nat)

;;Examples:
(check-expect (unique-email-senders (list email3 email0)) (list 1 2))
(check-expect (unique-email-senders (list email6)) (list 1 2))
(check-expect (unique-email-senders (list email1 email2 email3))
              (list 1 2 3 4 5 8))

(define (unique-email-senders email-list)
  (local
    ;;(get-all-id email-list) produces a list of all of the staff id's in
    ;;   email-list
    ;;get-all-id: (listof Email) -> (listof Nat)
    [(define (get-all-id email-list)
       (cond
         [(empty? email-list) empty]
         [else (append
                (list (email-staff-id (first email-list)))
                (get-all-id (rest email-list))
                (get-all-id (email-reply (first email-list))))]))
     ;;(sort-id id-list) produces a new list of ids in non-decreasing order
     ;;sort-id: (listof Nat) -> (listof Nat)
     (define (sort-id id-list)
       (cond
         [(empty? id-list) empty]
         [else (insert (first id-list) (sort-id (rest id-list)))]))
     ;;(insert id sorted-list) inserts id into its correct place in the
     ;;   non-decreasing list 'sorted-list'
     ;;insert: Nat (listof Nat) -> (listof Nat)
     ;;requires: sorted-list is sorted in non-decreasing order
     (define (insert id sorted-list)
       (cond
         [(empty? sorted-list) (cons id empty)]
         [(<= id (first sorted-list)) (cons id sorted-list)]
         [else (cons (first sorted-list) (insert id (rest sorted-list)))]))
     ;;(remove-duplicates sorted-list) produces a list with all duplicate
     ;;   members removed
     ;;remove-duplicates: (listof Nat) -> (listof Nat)
     ;;requires: sorted-list is sorted in non-decreasing order
     (define (remove-duplicates sorted-list)
       (cond
         [(empty? sorted-list) empty]
         [(empty? (rest sorted-list)) (list (first sorted-list))]
         [(= (first sorted-list) (second sorted-list)) (remove-duplicates (cons (first sorted-list) (rest (rest sorted-list))))]
         [else (cons (first sorted-list) (remove-duplicates (rest sorted-list)))]))]
    (remove-duplicates (sort-id (get-all-id email-list)))))

;;Tests:
(check-expect (unique-email-senders (list email6 email7 email8)) (list 1 2 4 5))
(check-expect (unique-email-senders (list email5 email8)) (list 1 2 3 4 5))
(check-expect (unique-email-senders (list email3 email4 email5 email6 email7))
              (list 1 2 3))
(check-expect (unique-email-senders empty) empty)



;;******************************************************************************



;;part (d)

;;(sent-email-summary email-list) produces a list of the unique email senders
;;   from email-list along with the number of emails they sent

;;sent-email-summary: (listof Email) -> (listof (list Nat Nat))

;;Examples:
(check-expect (sent-email-summary (list email4 email5))
              (list (list 1 2) (list 2 1) (list 3 1)))
(check-expect (sent-email-summary (list email1 email2 email3))
              (list (list 1 4) (list 2 2) (list 3 2) (list 4 2) (list 5 4)
                    (list 8 2)))
(check-expect (sent-email-summary (list email3 email2 email8))
              (list (list 1 2) (list 2 1) (list 3 1) (list 4 2) (list 5 3)
                    (list 8 1)))

(define (sent-email-summary email-list)
  (local
    [(define unique-id-list (unique-email-senders email-list))
     ;;(get-emails-of-id-list unique-id-list) produces a list of the ids from
     ;;   unique-id-list along with how many emails each of the staff-members
     ;;   that the ids correspond to sent
     ;;get-emails-of-id-list: (listof Nat) -> (listof (list Nat Nat))
     (define (get-emails-of-id-list unique-id-list)
       (cond
         [(empty? unique-id-list) empty]
         [else (cons (list (first unique-id-list) (get-emails-of-id (first unique-id-list) email-list))
                     (get-emails-of-id-list (rest unique-id-list)))]))
     ;;(get-emails-of-id id email-list) produces the number of emails the staff
     ;;   member that id corresponds to sent
     ;;get-emails-of-id: Nat (listof Emails) -> Nat
     ;;requires: id is in email-list
     (define (get-emails-of-id id email-list)
       (cond
         [(empty? email-list) 0]
         [(= id (email-staff-id (first email-list)))
          (+ 1
             (get-emails-of-id id (rest email-list))
             (get-emails-of-id id (email-reply (first email-list))))]
         [else (+ 0
             (get-emails-of-id id (rest email-list))
             (get-emails-of-id id (email-reply (first email-list))))]))]
          (get-emails-of-id-list unique-id-list)))

;;Tests:
(check-expect (sent-email-summary empty) empty)
(check-expect (sent-email-summary (list email6 email7 email8))
              (list (list 1 3) (list 2 1) (list 4 1) (list 5 1)))
(check-expect (sent-email-summary (list email5 email8))
              (list (list 1 2) (list 2 1) (list 3 1) (list 4 1) (list 5 1)))
(check-expect (sent-email-summary (list email3 email4 email5 email6 email7))
              (list (list 1 4) (list 2 3) (list 3 1)))



;;******************************************************************************



;;part (e)

;;(email-offenders email-list cutoff) produces a sorted (non-decreasing) list of 
;;   staff ids of the staff in 'email-list' who sent strictly more emails than 
;;   'cutoff'

;;email-offenders: (listof Email) Nat -> (listof Nat)

;;Examples:
(check-expect (email-offenders (list email4 email5) 1) (list 1))
(check-expect (email-offenders (list email1 email2 email3) 3) (list 1 5))
(check-expect (email-offenders (list email1 email2 email3) 2) (list 1 5))

(define (email-offenders email-list cutoff)
  (local
    [(define id-email-summary (sent-email-summary email-list))
     ;;(compare-cutoff id-email-summary cutoff) produces a sorted 
     ;;   (non-decreasing) list of id that are in id-email-summary and whose 
     ;;   corresponding staff members sent strictly more emails than 'cutoff'
     ;;compare-cutoff: (listof Nat) Nat -> (listof Nat)
     ;;requires: id-email-summary is sorted in non-decreasing order
     (define (compare-cutoff id-email-summary cutoff)
       (cond
         [(empty? id-email-summary) empty]
         [(< cutoff (second (first id-email-summary)))
          (cons (first (first id-email-summary)) (compare-cutoff (rest id-email-summary) cutoff))]
         [else (compare-cutoff (rest id-email-summary) cutoff)]))]
    (compare-cutoff id-email-summary cutoff)))

;;Tests:
(check-expect (email-offenders empty 0) empty)
(check-expect (email-offenders (list email1 email2 email3) 100) empty)
(check-expect (email-offenders (list email1 email2 email3) 0)
              (list 1 2 3 4 5 8))
(check-expect (email-offenders (list email1 email2 email3) 1)
              (list 1 2 3 4 5 8))
(check-expect (email-offenders (list email1 email2 email3) 1)
              (list 1 2 3 4 5 8))
(check-expect (email-offenders (list email3 email4 email5 email6 email7) 3)
              (list 1))
(check-expect (email-offenders (list email3 email4 email5 email6 email7) 2)
              (list 1 2))
(check-expect (email-offenders (list email3 email2 email8) 3)
              empty)
(check-expect (email-offenders (list email3 email2 email8) 2)
              (list 5))
(check-expect (email-offenders (list email3 email2 email8) 1)
              (list 1 4 5))
























