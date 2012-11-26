; Assignment 17
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Write filters that perform following operations
; a)      Display all vegetables (define a predicate named vegetable? that returns true only if the food type is "vegetable".)
; b)      Display all blackberries (define a predicate named blackberry? that return true only if the food is " Blackberry")
; c)      Display food from OR (define a predicate named oregon? that returns true only if the state is "OR")


;(define class-size
            ;'(("CSE100" . 120) ("CSE110" . 140) ("CSE205" . 100) ("CSE240" . 80)  ("CSE310" . 70) ("CSE360" . 75) ("CSE420" . 65)))
;
;(define big-class? (lambda (x) (>= (cdr x) 100)))
;
;(display (filter big-class? class-size))
;(newline)

(define food '( 
               ("Pecan" . (1982 .("nut". "AL"))) 
               ("Blackberry" . (2004 .("fruit". "AL")))  
               ("Peach" . (2006 .("fruit". "AL"))) 
               ("Rice" . (2007 .("grain". "AR"))) 
               ("Orange" . (2005 .("fruit". "FL"))) 
               ("Huckleberry" . (2000 .("fruit". "ID")))
               ("Blackberry" . (2004 .("fruit". "KY")))
               ("Strawberry" . (1980 .("fruit". "LA")))
               ("WildBlueberry" . (1991 .("fruit". "ME")))
               ("BlueCrab" . (2000 .("food". "MD")))
               ("HoneycrispApple" . (2006 .("fruit". "MN")))
               ("Pumpkin" . (2000 .("fruit". "NH")))
               ("Chile" . (1965 .("vegetable". "NM")))
               ("Blueberry" . (2001 .("fruit". "NC")))
               ("ChokeCherry" . (2007 .("fruit". "ND")))
               ("WaterMelon" . (2007 .("vegetable". "OK")))
               ("Pear" . (2000 .("fruit". "OR")))
               ("Hazelnut" . (2000 .("nut". "OR")))
               ("Peach" . (1984 .("fruit". "SC")))
               ("Tomato" . (2003 .("fruit". "TN")))
               ("Jalapeno" . (1995 .("vegetable". "TX")))
               ("Apple" . (2000 .("fruit". "WA"))) ; database of foods         
  ))  

; filer to display all vegetables (define a predicate named vegetable? that returns true only if the food type is "vegetable".)
(define vegetable? (lambda (x) (string=? "vegetable" (caddr x))))

; Filter to display all blackberries (define a predicate named blackberry? that return true only if the food is " Blackberry")
(define blackberry? (lambda (x) (string=? "Blackberry" (car x))))

; Filter to display food from OR (define a predicate named oregon? that returns true only if the state is "OR")
(define oregon? (lambda (x) (string=? "OR" (cdddr x))))

 

(display (filter vegetable? food)) ; display the results of applying a filter
(newline)
(newline)

(display (filter blackberry? food)) ; display the results of applying a filter
(newline)
(newline)

(display (filter oregon? food)) ; display the results of applying a filter
(newline)
(newline)


 
