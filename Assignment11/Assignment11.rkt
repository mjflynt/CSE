; Assignment 11
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Create a Racket procedure find_min that reads numbers from the keyboard 
;              until 0 is read, and display the minimum of all read numbers. Note that 0 
;              is included in the computation.

(define (find_min x)
  (define readval (read)) ; grab the next kb input.
  (if (= readval 0) ; and if it is a zero
      (if (< 0 x) ; determine if zero is the smallest number
          0 ; if so return it
          x ; otherwise return what actually was the smallest number
          )
      (if (< readval x) ; if it isn't a zero the call the process again with the correct param.
          (find_min readval) ; the newly read value is the smallest read so far - use it
          (find_min x) ; or the newly read value is begger than a previous value to ignore it. 
          )
      )
  )


(display (find_min 0)) ; start the program. The param can be zero or any positive to initiate.

