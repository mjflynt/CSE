
(define (remove_at thelist theindex)
  (if (> theindex (- (length thelist) 1))
      "not found"
       (if (= theindex 0)
          (cdr thelist)
          (append (list(car thelist)) (remove_at (cdr thelist) (- theindex 1)))
          )
       )
  )



(define (remove_at1 thelist theindex )
  (if (null? thelist) 
        (display "not found")

      (if (= theindex 0)
          (cdr thelist)
          (append (list(car thelist)) (remove_at (cdr thelist) (- theindex 1)))
          )
      )
  )

(display (remove_at (read) (read))) 