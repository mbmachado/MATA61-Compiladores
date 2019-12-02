; MATA60 - Robot-L intermediate code
; base code for controlling the robot with few procedures

#start=robot.exe#

name "robot"

#make_bin#
#cs = 500#
#ds = 500#
#ss = 500#
#sp = ffff#
#ip = 0#

; robot base i/o port:
r_port equ 9

;=================================== BEGIN PROGRAM

call wait_robot

call exam_front
; get result of exam:
in al, r_port + 1
call wait_exam

; nothing found?
cmp al, 0
je continue  ; - yes, so continue.

; wall front?
cmp al, 255  
je continue  ; - yes, so continue.

; switched-on lamp front?
cmp al, 7
je continue  ; - yes, so continue.

; switched-off lamp front?
cmp al, 8
je continue  ; - yes, so continue.

; switched-on lamp left?
cmp al, 9
je continue  ; - yes, so continue.

; switched-off lamp left?
cmp al, 10
je continue  ; - yes, so continue.

; switched-on lamp right?
cmp al, 11
je continue  ; - yes, so continue.

; switched-off lamp right?
cmp al, 12
je continue  ; - yes, so continue.

; wall left?
cmp al, 240  
je continue  ; - yes, so continue.

; wall right?
cmp al, 15  
je continue  ; - yes, so continue.

;=================================== END PROGRAM
;=================================== BEGIN PROCEDURES

; do nothing procedure:
do_nothing proc
mov al, 0
out r_port, al
ret
do_nothing endp

; move robot forward:
move_forward proc
mov al, 1
out r_port, al
ret
move_forward endp

; turn robot left:
turn_left proc
mov al, 2
out r_port, al
ret
turn_left endp

; turn robot right:
turn_right proc
mov al, 3
out r_port, al
ret
turn_right endp

; examines an object in front using sensor:
exam_front proc
mov al, 4
out r_port, al
ret
exam_front endp

; switch on the lamp:
switch_on_lamp proc
mov al, 5
out r_port, al
ret
switch_on_lamp endp

; switch off the lamp:
switch_off_lamp proc
mov al, 6
out r_port, al
ret
switch_off_lamp endp

; this procedure does not
; return until robot is ready
; to receive next command:
wait_robot proc
; check if robot busy:
busy1: in al, r_port + 2
      test al, 00000010b
      jnz busy1 ; busy, so wait.
ret    
wait_robot endp

; this procedure does not
; return until robot completes
; the examination:
wait_exam proc
; check if has new data:
busy2: in al, r_port + 2
       test al, 00000001b
       jz busy2 ; no new data, so wait.
ret    
wait_exam endp

;=================================== END PROCEDURES