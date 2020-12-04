;this progam is to be used with PennSim.jar. the program simulates a simon says game where colors flash across the screen
;and the user must correctly enter the correct order by inputting the color's corresponding letter (r for red, b for blue, ect.)
;there are multiple rounds a user must advance past.



.orig x3000
 	
    lea r0, welcome 
	puts

    LD R5, PIXEL ;load the counter for drawing pixels
	START	ld 	R3, GMStart 	; Load R3 Center of Graphic array

    ld 	R4, RED	; Load R4 Color Red 
    
LOOP
    STR	R4, R3, #0	; Make pixel at current location red
    ADD R3, R3, #1	;move location right
    ADD R5, R5, #1 ;increment pixel counter
    BRz NEXT ;moves on to next routine once counter is zero
    BRn	LOOP ;continues throught the loop of drawing each pixel
NEXT
    LD R5, PIXEL ;loads pixel counter
    ld 	R3, GMStart 	; Load R3 Center of Graphic array
    ld 	R4, GREEN	; Load R4 Color green

LOOP2
    STR	R4, R3, #0 ;makes pixel green
    ADD R3, R3, #1	;increments location
    ADD R5, R5, #1 ;increment pixel counter
    BRz NEXT2 ;calls next color
    BRn	LOOP2
NEXT2
    LD R5, PIXEL  ;loads pixel counter
    ld 	R3, GMStart  ;loads graphic memory start	
    ld 	R4, YELLOW	; Load R4 Color yellow

LOOP3
    STR	R4, R3, #0	; makes pixel yellow
    ADD R3, R3, #1	; move location
    ADD R5, R5, #1 ;increment counter
    BRz NEXT3 ;next color 
    BRn	LOOP3

NEXT3
    LD R5, PIXEL
    ld 	R3, GMStart 	
    ld 	R4, BLUE	

LOOP4
    STR	R4, R3, #0	
    ADD R3, R3, #1	
    ADD R5, R5, #1
    BRz NEXT4
    BRn	LOOP4
NEXT4
    LD R5, PIXEL 
    ld 	R3, GMStart 	
    ld 	R4, GREEN	

LOOP5
    STR	R4, R3, #0	
    ADD R3, R3, #1	
    ADD R5, R5, #1
    BRZ NEXT5
    BRn	LOOP5
NEXT5   
    LD R5, PIXEL 
    ld 	R3, GMStart 	
    ld 	R4, YELLOW	

LOOP6
    STR	R4, R3, #0	
    ADD R3, R3, #1	
    ADD R5, R5, #1
    BRz CLEAR
    BRn	LOOP6
CLEAR
    LD R5, PIXEL 
    ld 	R3, GMStart 	
    ld 	R4, WHITE	

CLEARLOOP ;clears last color
    STR	R4, R3, #0	; Make pixel at current location white
    ADD R3, R3, #1	;move location right
    ADD R5, R5, #1
    BRz ARRAYCNT ;moves on to check user input
    BRn	CLEARLOOP

ARRAYCNT
    LD R2, X ;counts place in array
    LEA R6, COLORS ;LOAD ARRAY INTO R6

        
WHILE
    ADD R2, R2, #0 ;check counter to see if reached end of array
    BRZ ENDIFWIN ;if end of array, win 
    ADD R2, R2, #1 ;increments counter for number of colors left to guess
    LDR R4, R6, #0 ;loads current array color
    ADD R6, R6, #1 ;increments to next array position
    LEA R0, INPUTPROMPT ;PROMT FOR INPUT
    PUTS
    GETC    ;reads a char
    OUT ;puts char to screen
    ADD R1, R0, #0  ;R1 <- R0
    NOT R4, R4  ; MAKE R4 NEG 
    ADD R4, R4, #1          
    ADD R5, R4, R1 ; SUBTRACT R4 AND R1
    BRNP IF ;IF POS OR NEG, LOSE
    BRZ WHILE

        
YOUWIN     
    LEA R0, WINPROMPT
    PUTS
    BR ENDIF ;ENDS GAME

IF  
    LEA R0, LOSEPROMPT    ;loads losing message
    PUTS    
    BR ENDIF

ENDIFWIN
    LEA R0, WINPROMPT
    PUTS
    HALT

ENDIF
        
    HALT


DONE
    Halt
COLORS ;array of colors for each round 
    .FILL x72 ;red
    .FILL x67 ;green
    .FILL x79 ;yellow
    .FILL x62 ;blue
    .FILL x67 ;green
    .FILL x79 ;yellow
    X .FILL #-6 ;array counter
    PIXEL .FILL #-7936 ;pixel counter, fills half of graphics window
    RED	.FILL	x7C00 ;red
    GREEN .FILL x03E0 ;green   
    WHITE .FILL x7FFF ;white
    BLUE .FILL x001F ;blue
    BLACK .FILL x0000 ;black
    YELLOW .FILL xFFFF00 ;yellow
    GMStart	.FILL	xC000	; START OF GRAPHIC MEMORY		
    welcome .stringz "Simon Says"

    STARTPROMPT .stringz "\nSimon's Turn: \n"
    LOSEPROMPT .stringz "\nSimon Wins!"
    WINPROMPT .stringz "\nYou Win!\n"
    INPUTPROMPT .stringz "\nenter color: "
.end
