; Assignment 12
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Create a Racket procedure procedure compute_pos that reads numbers from the 
;              keyboard until 0 is read, count how many positive numbers are read, and also 
;              compute the sum of only positive numbers, and display the count and the sum 
;              of positive numbers in different lines. Note that 0 is not included in the computations.


(define (compute_pos count_pos sum_pos)
  (define readval (read)) ; grab the next kb input
  (if (= readval 0) ; and if it is zero
      (begin ; then output the report of statistics
        (display "positive count: ")
        (display count_pos)
        (newline)
        (display "positive sum: ")
        (display sum_pos)
        )
      (if (> readval 0) ; if it is not zero 
          (compute_pos (+ count_pos 1) (+ sum_pos readval)) ; but it is positive then call again with updated params
          (compute_pos count_pos sum_pos) ; otherwise just call again with same params
          )
      )
  )

(compute_pos 0 0) ; start the program with initial conditions of 0 count and 0 sum

  