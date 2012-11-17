; Assignment 14
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Rewrite the above expression without using “let*” and using “let” and “define” 
; statement 

;(display "original way with let*")
;(newline)
;
;(let* ((x 9) (y (- 4 11)) (z (+ x y)) (w (* z x)))
  ;(write x)
  ;(newline)
  ;(write y)
  ;(newline)
  ;(write z)
  ;(newline)
  ;(write w)
  ;(newline)
;)
;
;(newline)
;(display "new way with just let")
;(newline)

(let ((x 9) (y (- 4 11))) ; I noticed that the way these vars are defined in the let* 
  (let ((z (+ x y)))      ; function allows them to be nested instead. No define is 
    (let ((w (* z x)))    ; required in this particular case as the scopes are correctly handled.
      (write x) ; the following is the original outputs...
      (newline)
      (write y)
      (newline)
      (write z)
      (newline)
      (write w)
      (newline)
      )
    )
  )
