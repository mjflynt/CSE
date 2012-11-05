; Assignment 10
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Racket procedure find_min2 that reads 2 numbers from the keyboard, and returns the minimum of two.


(define (find_min2 a b) 
  (if (< a b)
      a
      b
      )
  )

(display (find_min2 (read) (read)))
