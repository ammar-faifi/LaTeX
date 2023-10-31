;;;;;;;;;;;;;;;; CODE OF PROBLEM 01 ;;;;;;;;;;;;;;;;;;;;
(define (svmLoss scores)
  (let ((sj (car scores))
        (sy (cadr scores)))
    (if (> (- (+ 1 sj) sy) 0)
        (- (+ 1 sj) sy)
        0)))

; Sample runs
(display (svmLoss '(3.5 2)))    ; Output: 2.5
(newline)
(display (svmLoss '(3.15 4.97))) ; Output: 0
(newline)

;;;;;;;;;;;;;;;; CODE OF PROBLEM 02 ;;;;;;;;;;;;;;;;;;;;

(define (orderMingle xs ys)

    (define (merge-alternate lst1 lst2)
      (cond
        ((null? lst1) lst2)  ; If lst1 is empty, return lst2
        ((null? lst2) lst1)  ; If lst2 is empty, return lst1
        (else
         (cons (car lst1)    ; Take the first element from lst1
                ; Recursively merge the rest, not swiping between lst2 and lst1 as args
               (merge-alternate lst2 (cdr lst1)))))) 

  (define xs-descending (sort (map number->string xs) string>?))
  (define ys-descending (sort (map symbol->string ys) string>?))
  (define merged-list (merge-alternate xs-descending ys-descending))
  
  merged-list)

; Sample run
(display (orderMingle '(15 52 77) '(d y w)))
(newline)

