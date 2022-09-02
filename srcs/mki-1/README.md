# 목표

Raycasting 알고리즘을 이용해서 게임을 만들어라.

---

# 필요한 지식

- C
- Makefile
- mlx 사용법
- 벡터
- 삼각함수
- 회전행렬
- Raycasting

---

# 개발 일지

### 시작

- 문제 분석하기
    - 문제를 분석하고 내가 무엇을 어떻게 만들 것인지 전략을 짜봅시다.

    ### 우선 문제부터 볼까요?

    - 그 다음 자료부터 수집해야겠죠? 과제 페이지에 있는 minilibx로 뭔가를 하는 것 같은데...
    - mlx 라이브러리안의 함수들이 각각 어떤 역할을 하는지 이것저것 해봅시다.
    - [https://github.com/taelee42/mlx_example](https://github.com/taelee42/mlx_example)를 따라해보면 도움이 됩니다.
    - mlx를 이용해서 차근차근 과제를 진행해 나가봅시다.
    - 플레이어 만드는 함수 구현하기
    - 플레이어 키보드 입력 받기
    - 동시 입력 구현하기
    - 격자 만드는 함수 구현하기
    - 벽 만드는 함수 구현하기
    - Makefile, header, main만들기
    - 함수는 하나에 한 가지 기능만! 언제든지 불러와서 쓸 수 있게 범용성 있는 함수를 만들어보아요.
- 자료 조사
    - 음... mlx는 약간 익숙해진 것 같은데... 이제 뭘 해야 하죠? 도저히 혼자서는 못하겠어요. 친구들아 부탁해!
    - 자료만 훑어보는 걸로 하루를 보내봐요.
    - [https://lodev.org/cgtutor/raycasting.html](https://lodev.org/cgtutor/raycasting.html) 약칭 '로데브'라고 하는 이 사이트에는 cub3d의 정답이 들어있습니다. 하지만 영어이기 때문에, 영어가 익숙치 않은 사람들에게는 적합하지 않은 자료입니다.
    - 그래서 [https://github.com/365kim/raycasting_tutorial](https://github.com/365kim/raycasting_tutorial)에 번역을 해 주신 cadet분이 계십니다. 이것을 보고 차근차근 이해하면 될 것 같지만 여전히 모르겠습니다.
    - minckim님이 정리해 놓은 pdf 파일과 github도 있습니다. [https://github.com/minckim0/cub3d_lect](https://github.com/minckim0/cub3d_lect)
    - sucho님이 정리해 놓은 자료도 있습니다. [https://github.com/sungyongcho/ii2r](https://github.com/sungyongcho/ii2r)
    - [https://42kchoi.tistory.com/category/Code 42/miniLibX%2C 3서클](https://42kchoi.tistory.com/category/Code%2042/miniLibX%2C%203%EC%84%9C%ED%81%B4) 이 자료도 도움이 될 겁니다.
    - 참고자료를 이용해서 벽을 세우는 방법을 이해하고 구현해야 합니다.
    - 그래서... 벽을 도대체 어떻게 세우죠?
    - 광선을 쏘고, DDA 알고리즘을 이용해서 벽을 그리라는데... 정말 모르겠어요...
    - 자 그래서... 블로그를 봐도 하나도 모르겠으니... 하나씩 격파를 해보죠.
- 문제 분할하기
- Makefile 만들기

    문제: mlx라이브러리 libmlx.a와 libft라이브러리 libft.a 두 개를 합치고 싶은데 ar 명령어로는 동작하지 않습니다.

    해결: libtool 명령어를 이용합시다.

    ```cpp
    libtool -static libft.a libmlx.a -o cub3d.a
    ```

    참고: [https://kwonsaw.tistory.com/42](https://kwonsaw.tistory.com/42)

### 2D로 그려보기

- mlx 튜토리얼 따라해보기
    - mlx manpage
        - mlx

            ```
            MiniLibX(3)                                                                                       MiniLibX(3)

            NAME
                   MiniLibX - Simple Graphical Interface Library for students

            SYNOPSYS
                   #include <mlx.h>

                   void *
                   mlx_init ();

            DESCRIPTION
                   MiniLibX  is  an  easy way to create graphical software, without any X-Window/Cocoa programming knowl-
                   edge. It provides simple window creation, a drawing tool, image and basic events management.

            BSD/LINUX X-WINDOW CONCEPT
                   X-Window is a network-oriented graphical system for Unix.  It is based on two main parts:
                   On one side, your software wants to draw something on the screen and/or get keyboard & mouse  entries.
                   On  the  other  side, the X-Server manages the screen, keyboard and mouse (It is often refered to as a
                   "display").
                   A network connection must be established between these two entities to send drawing orders  (from  the
                   software to the X-Server), and keyboard/mouse events (from the X-Server to the software).

            MACOSX CONCEPT
                   The MacOSX operating system handle graphical access to the screen (or "display").
                   On  one side, your software wants to draw something on the screen and/or get keyboard & mouse entries.
                   On the other side, the underlying MacOSX graphical framework that handles the  screen,  the  windowing
                   system, keyboard and mouse.
                   A connection between these two entities must be established.

            INCLUDE FILE
                   mlx.h should be included for a correct use of the MiniLibX API.  It only contains function prototypes,
                   no structure is needed.

            LIBRARY FUNCTIONS
                   First of all, you need to initialize the connection between your software and the display.  Once  this
                   connection  is  established,  you'll  be  able  to  use other MiniLibX functions to send the graphical
                   orders, like "I want to draw a yellow pixel in this window" or "did the user hit a key?".

                   The mlx_init function will create this connection. No parameters are needed, ant it will return a void
                   * identifier, used for further calls to the library routines.

                   All other MiniLibX functions are described in the following man pages:

                   mlx_new_window      : manage windows

                   mlx_pixel_put       : draw inside window

                   mlx_new_image       : manipulate images

                   mlx_loop            : handle keyboard or mouse events

            LINKING MiniLibX on BSD/Linux and X-Window
                   To  use  MiniLibX  functions,  you'll need to link your software with several libraries, including the
                   MiniLibX library itself.  To do this, simply add the following arguments at linking time:

                   -lmlx -lXext -lX11

                   You may also need to specify the path to these libraries, using the -L flag.

            LINKING MiniLibX on MACOSX
                   To use MiniLibX functions, you'll need to link your software with the MiniLibX  library,  and  several
                   system frameworks:

                   -lmlx -framework OpenGL -framework AppKit

                   You may also need to specify the path to the MiniLibX library, using the -L flag.

            RETURN VALUES
                   If mlx_init() fails to set up the connection to the graphical system, it will return NULL, otherwise a
                   non-null pointer is returned as a connection identifier.

            SEE ALSO
                   mlx_new_window(3), mlx_pixel_put(3), mlx_new_image(3), mlx_loop(3)

            AUTHOR
                   Copyright ol@ - 2002-2015 - Olivier Crouzet

                                                          September 19, 2002                                  MiniLibX(3)
            ```

        - mlx_new_window

            ```
            MiniLibX(3)                                                                                       MiniLibX(3)

            NAME
                   MiniLibX - Managing windows

            SYNOPSYS
                   void *
                   mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

                   int
                   mlx_clear_window ( void *mlx_ptr, void *win_ptr );

                   int
                   mlx_destroy_window ( void *mlx_ptr, void *win_ptr );

            DESCRIPTION
                   The mlx_new_window () function creates a new window on the screen, using the size_x and size_y parame-
                   ters to determine its size, and title as the text that should be displayed in the window's title  bar.
                   The  mlx_ptr  parameter  is  the connection identifier returned by mlx_init () (see the mlx man page).
                   mlx_new_window () returns a void * window identifier that can be used by other MiniLibX  calls.   Note
                   that the MiniLibX can handle an arbitrary number of separate windows.

                   mlx_clear_window () and mlx_destroy_window () respectively clear (in black) and destroy the given win-
                   dow. They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a
                   window identifier.

            RETURN VALUES
                   If mlx_new_window() fails to create a new window (for wathever reason), it will return NULL, otherwise
                   a non-null pointer is returned as a window identifier.  mlx_clear_window and mlx_destroy_window  right
                   now return nothing.

            SEE ALSO
                   mlx(3), mlx_pixel_put(3), mlx_new_image(3), mlx_loop(3)

            AUTHOR
                   Copyright ol@ - 2002-2015 - Olivier Crouzet

                                                          September 19, 2002                                  MiniLibX(3)
            ```

        - mlx_pixel_put

            ```
            MiniLibX(3)                                                                                       MiniLibX(3)

            NAME
                   MiniLibX - Drawing inside windows

            SYNOPSYS
                   int
                   mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

                   int
                   mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );

            DESCRIPTION
                   The  mlx_pixel_put () function draws a defined pixel in the window win_ptr using the ( x , y ) coordi-
                   nates, and the specified color . The origin (0,0) is the upper left corner of the window, the x and  y
                   axis respectively pointing right and down. The connection identifier, mlx_ptr , is needed (see the mlx
                   man page).

                   Parameters for mlx_string_put () have the same meaning. Instead  of  a  simple  pixel,  the  specified
                   string will be displayed at ( x , y ).

                   In  both  functions, it is impossible to display anything outside the specified window, nor display in
                   another window in front of the selected one.

            COLOR MANAGEMENT
                   The color parameter has an integer type. The displayed color needs to be encoded in this integer, fol-
                   lowing  a  defined scheme. All displayable colors can be split in 3 basic colors: red, green and blue.
                   Three associated values, in the 0-255 range, represent how much of each color is mixed  up  to  create
                   the original color. Theses three values must be set inside the integer to display the right color. The
                   three least significant bytes of this integer are filled as shown in the picture below:

                           | 0 | R | G | B |   color integer
                           +---+---+---+---+

                   While filling the integer, make sure you avoid endian problems. Remember that the "blue"  byte  should
                   always be the least significant one.

            SEE ALSO
                   mlx(3), mlx_new_window(3), mlx_new_image(3), mlx_loop(3)

            AUTHOR
                   Copyright ol@ - 2002-2015 - Olivier Crouzet

                                                          September 19, 2002                                  MiniLibX(3)
            ```

        - mlx_new_image

            ```
            MiniLibX(3)                                                                                       MiniLibX(3)

            NAME
                   MiniLibX - Manipulating images

            SYNOPSYS
                   void *
                   mlx_new_image ( void *mlx_ptr, int width, int height );

                   char *
                   mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

                   int
                   mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );

                   unsigned int
                   mlx_get_color_value ( void *mlx_ptr, int color );

                   void *
                   mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );

                   void *
                   mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

                   int
                   mlx_destroy_image ( void *mlx_ptr, void *img_ptr );

            DESCRIPTION
                   mlx_new_image  ()  creates  a new image in memory. It returns a void * identifier needed to manipulate
                   this image later. It only needs the size of the image to be created, using the width and height param-
                   eters, and the mlx_ptr connection identifier (see the mlx manual).

                   The  user  can  draw inside the image (see below), and can dump the image inside a specified window at
                   any time to display it on the screen. This is done using mlx_put_image_to_window (). Three identifiers
                   are  needed  here,  for  the connection to the display, the window to use, and the image (respectively
                   mlx_ptr , win_ptr and img_ptr ). The ( x , y ) coordinates define where the image should be placed  in
                   the window.

                   mlx_get_data_addr  () returns information about the created image, allowing a user to modify it later.
                   The img_ptr parameter specifies the image to use. The three next parameters should be the addresses of
                   three  different valid integers.  bits_per_pixel will be filled with the number of bits needed to rep-
                   resent a pixel color (also called the depth of the image).  size_line is the number of bytes  used  to
                   store one line of the image in memory.  This information is needed to move from one line to another in
                   the image.  endian tells you wether the pixel color in the image needs to be stored in little endian (
                   endian == 0), or big endian ( endian == 1).

                   mlx_get_data_addr  returns  a char * address that represents the begining of the memory area where the
                   image is stored. From this adress, the first bits_per_pixel bits represent  the  color  of  the  first
                   pixel  in  the  first  line of the image. The second group of bits_per_pixel bits represent the second
                   pixel of the first line, and so on.  Add size_line to the adress to get the  begining  of  the  second
                   line. You can reach any pixels of the image that way.

                   mlx_destroy_image destroys the given image ( img_ptr ).

            STORING COLOR INSIDE IMAGES
                   Depending  on the display, the number of bits used to store a pixel color can change. The user usually
                   represents a color in RGB mode, using one byte for each component  (see  mlx_pixel_put  manual).  This
                   must  be translated to fit the bits_per_pixel requirement of the image, and make the color understand-
                   able to the graphical system.  That is the purpose of the mlx_get_color_value () function. It takes  a
                   standard RGB color parameter, and returns an unsigned int value.  The bits_per_pixel least significant
                   bits of this value can be stored in the image.

                   Keep in mind that the least significant bits position depends on the local computer's endian.  If  the
                   endian  of  the  image  (in fact the endian of the X-Server's computer for remote X11 display) differs
                   from the local endian, then the value should be transformed before being used.

            XPM IMAGES
                   The mlx_xpm_to_image () and mlx_xpm_file_to_image () functions will create a new image the  same  way.
                   They  will  fill  it  using  the specified xpm_data or filename , depending on which function is used.
                   Note that MiniLibX does not use the standard Xpm library to deal with xpm images. You may not be  able
                   to read all types of xpm images. It however handles transparency.

            RETURN VALUES
                   The    three    functions    that    create   images,   mlx_new_image()   ,   mlx_xpm_to_image()   and
                   mlx_xpm_file_to_image() , will return NULL if an  error  occurs.  Otherwise  they  return  a  non-null
                   pointer as an image identifier.

            SEE ALSO
                   mlx(3), mlx_new_window(3), mlx_pixel_put(3), mlx_loop(3)

            AUTHOR
                   Copyright ol@ - 2002-2015 - Olivier Crouzet

                                                          September 19, 2002                                  MiniLibX(3)
            ```

        - mlx_loop

            ```
            MiniLibX(3)                                                                                       MiniLibX(3)

            NAME
                   MiniLibX - Handle events

            SYNOPSYS
                   int
                   mlx_loop ( void *mlx_ptr );

                   int
                   mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

                   int
                   mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

                   int
                   mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

                   int
                   mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );

            EVENTS
                   Both X-Window and MacOSX graphical systems are bi-directionnal.  On one hand, the program sends orders
                   to the screen to display pixels, images, and so on. On the other hand, it can get information from the
                   keyboard and mouse associated to the screen. To do so, the program receives "events" from the keyboard
                   or the mouse.

            DESCRIPTION
                   To receive events, you must use mlx_loop (). This function never returns. It is an infinite loop  that
                   waits  for  an  event,  and  then  calls a user-defined function associated with this event.  A single
                   parameter is needed, the connection identifier mlx_ptr (see the mlx manual).

                   You can assign different functions to the three following events:
                   - A key is pressed
                   - The mouse button is pressed
                   - A part of the window should be re-drawn (this is called an "expose" event, and it is your  program's
                   job to handle it).

                   Each window can define a different function for the same event.

                   The  three  functions  mlx_key_hook (), mlx_mouse_hook () and mlx_expose_hook () work exactly the same
                   way.  funct_ptr is a pointer to the function you want to be called when an event occurs. This  assign-
                   ment  is  specific to the window defined by the win_ptr identifier. The param adress will be passed to
                   the function everytime it is called, and should be used to store the parameters it might need.

                   The syntax for the mlx_loop_hook () function is identical to the previous ones, but the given function
                   will be called when no event occurs.

                   When it catches an event, the MiniLibX calls the corresponding function with fixed parameters:

                     expose_hook(void *param);
                     key_hook(int keycode,void *param);
                     mouse_hook(int button,int x,int y,void *param);
                     loop_hook(void *param);

                   These  function  names  are  arbitrary.  They here are used to distinguish parameters according to the
                   event. These functions are NOT part of the MiniLibX.

                   param is the address specified in the mlx_*_hook calls. This address is never used nor modified by the
                   MiniLibX.  On  key  and mouse events, additional information is passed: keycode tells you which key is
                   pressed (X11 : look for the include file "keysymdef.h", MacOS : create a small software and  find  out
                   by  yourself),  (  x  , y ) are the coordinates of the mouse click in the window, and button tells you
                   which mouse button was pressed.

            GOING FURTHER WITH EVENTS
                   The MiniLibX provides a much generic access to all type of events. The mlx.h include define mlx_hook()
                   in  the  same  manner  mlx_*_hook functions work. The event and mask values will be taken from the X11
                   include file "X.h" (even for MacOSX, for compatibility purposes)

                   See source code of mlx_int_param_event.c to find out how the MiniLibX will call your own function  for
                   a specific event.

            SEE ALSO
                   mlx(3), mlx_new_window(3), mlx_pixel_put(3), mlx_new_image(3)

            AUTHOR
                   Copyright ol@ - 2002-2015 - Olivier Crouzet

                                                          September 19, 2002                                  MiniLibX(3)
            ```

    - mlx function

        ### int mlx_clear_window(void *mlx_ptr, void *win_ptr)

        return void *0 if failed

        ### int mlx_destroy_image(void *mlx_ptr, void *img_ptr)

        ### int mlx_destroy_window(void *mlx_ptr, void *win_ptr)

        ### int mlx_do_key_autorepeatoff(void *mlx_ptr)

        ### int mlx_do_key_autorepeaton(void *mlx_ptr)

        ### int mlx_do_sync(void *mlx_ptr)

        ### int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)

        ### unsigned int mlx_get_color_value(void *mlx_ptr, int color)

        ### char * mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)

        return void *0 if failed

        ### int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)

        ### void *mlx_init()

        ### int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)

        ### int mlx_loop(void *mlx_ptr)

        ### int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)

        ### int mlx_mouse_get_pos(void *win_ptr, int *x, int *y)

        ### int mlx_mouse_hide()

        ### int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param)

        ### int mlx_mouse_move(void *win_ptr, int x, int y)

        ### int mlx_mouse_show()

        ### void * mlx_new_image(void *mlx_ptr, int width, int height)

        ### void * mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)

        ### int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)

        ### void * mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height)

        ### int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)

        endian : 0 = sever X is little endian, 1 = big endian
        endian : useless on macos, client and graphical framework have the same endian

        ### int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)

        ### void * mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)

        ### void * mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)

    - key data

        KEY_PRESS 2

        KEY_release 3

        KEY_EXIT 17

    - key data 2

        define KEY_ESC			53

        define KEY_Q	12

        define KEY_W	13

        define KEY_E	14

        define KEY_R	15

        define KEY_A	0

        define KEY_S	1

        define KEY_D	2

- 벡터 함수 만들기
    - minckim님의 자료부터 하나씩 해봅시다.

    [cub3d_lect.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1ca2eb09-1a72-485c-bf4b-89a7b67605c4/cub3d_lect.pdf)

    - [https://github.com/minckim0/cub3d_lect](https://github.com/minckim0/cub3d_lect)
    - 벡터를 사용해야 한다는데... 벡터 계산하는 함수부터 구현해볼까요?
    - 벡터 덧셈, 벡터 뺄셈, 벡터 곱셈, 벡터 나눗셈 함수를 만들어봅시다.
    - 그래서 우선 연립방정식을 푸는 함수를 구현해봅시다.
    - 그리고 벡터의 회전 함수를 구현해봅시다.
    - <math.h>라이브러리의 M_PI 매크로를 이용하면 pi 값을 얻을 수 있습니다.
    - 지금까지 완전 딴 생각을 하고 있었습니다.
    - 몇 번을 봐도 pdf는 불친절하고 코드는 아직 보기 싫어요. 이 pdf가 과연 친절한 걸까요?
    - 이제 그만하고 다시 로데브 번역본을 봅시다ㅠㅠ 지쳐가요...
- 맵 라인 그리기 - 격자 그리기
- 맵 벽 칠하기
- 플레이어 그리기
- 플레이어 움직이기 - 키 입력
- 동시 입력 구현하기
- 방향 벡터 구현하기 - 대각선과 회전 벡터
    - 방향 벡터를 구현 했습니다.
    - 그런데... 회전을 하려고 하니 방향이 반대로 갑니다. 알고 보니 LEFT, RIGHT KEY VALUE가 반대로 되어 있었군요... 이걸로 몇 일을 고생한건지...
    - 그리고 회전을 해도 대각선이 안나옵니다. 문제가 무엇일까요?
    - 대각선을 해결했습니다.
    - [https://m.blog.naver.com/PostView.nhn?blogId=kch8246&logNo=220821965260&proxyReferer=https:%2F%2Fwww.google.com%2F](https://m.blog.naver.com/PostView.nhn?blogId=kch8246&logNo=220821965260&proxyReferer=https:%2F%2Fwww.google.com%2F)
    - 대각선을 그리기 너무 어렵습니다.
- 카메라 벡터 구현하기
    - 이제 방향벡터와 수직인 카메라 벡터를 만들어봅시다.
    - 그런데 잘 그려지지는 않네요... 그냥 넘어갑시다.
- 광선 만들기
    - 코드를 전반적으로 수정했습니다.
    - pixel에 x, y를 주는 것만으로 알아서 계산하도록 ft_pixel을 만들었고, 모두 벡터 계산으로 pixel에 색을 바꾸는 식으로 코드를 수정했습니다.
    - 또한 시점과 종점, 그리고 색깔을 주면 알아서 라인이 그려지도록 만들었습니다.
    - 또한 라인을 그릴 때는 기준 delta만큼 반복하도록 코드를 수정했습니다. 그러니 방향벡터와 카메라 벡터가 잘 그려집니다.
    - 라인을 그릴 때 주의할 점은 double과 int의 변환으로 인한 차이를 아는 것 입니다. 기울기만큼 pixel 값을 변화 시킬 때는 double이지만, 실제로 pixel은 int밖에 없으므로 언제 int로 형변환해야 하는지 아는 것이 중요합니다.
    - 다음은 ray를 그릴 차례입니다.
- 광선 벽에 부딪히기

### 로데브 적용

- 로데브 이해하기
    - 아... 로데브를 몇 번을 봤는데... 이제야 이해가 되는 느낌이에요
    - 카메라 평면과 방향벡터를 구현해야 하고, 방향벡터는 광선이 아니군요...
    - 그럼 카메라 평면과 방향벡터를 구현해봅시다!
    - 생각을 해보니... 플레이어 이미지를 3 * 3으로 줬는데, 생각을 해보니 방향벡터 이미지도 또 만들어야 해서 그럴 바에는 그냥 한번에 플레이어와 방향벡터를 한 이미지로 처리하면 어떨까 하는 생각이 들어 플레이어를 맵처럼 크게 그리고 움직이게 하려고 했는데... 엉뚱한 결과가 나왔군요. 다시 방향벡터 이미지를 새로 만듭시다.
    - 사실 생각을 해보니... 방향벡터 이미지도 새로 만들어서 맵 위에 그리면... 그리지 않은 부분은 또 검은색이 맵 위에 덮어 씌워질텐데... 이거 완전 잘못 생각 하고 있었나봐요... 맵을 새로 계속 갱신해야 하나봐요.
    - 저처럼 이미지 두개로 하려고 하지 마세요... 심지어 이거 아직 튜토리얼입니다.
- 벽 세우기

    문제: 동서남북을 어떻게 인식할까요?

    해결: side와 ray.x, ray.y로 구분합시다.

    문제: 동서남북의 기준은 플레이어인가요 벽인가요?

    해결: 플레이어가 북쪽을 바라보면 북쪽 텍스쳐가 나와야 합니다. 즉 장애물은 남쪽방향이겠죠.

    문제: 로데브를 적용하세요. 그런데 왜 느릴까요?

    해결: 이미지를 넣을 때 x반복문 않에 넣어서 그러네요;;;

    문제: 회전이 되지 않아요.

    해결: 왜 sin, cos초기화를 제대로 안했죠?

    문제: 거리가 이상하게 구해져서 이미지에 값이 안들어가져요.

    해결: 맵을 복사할 때 memcpy를 사용하는데, 복사하는 함수 위치가 변수 초기화 이전에 있어서, 쓰레기 값이 들어갔네요...

    문제: 아래 유도 해설을 이해하세요.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7c067a1d-2b7d-4155-a61d-3c4919c13040/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7c067a1d-2b7d-4155-a61d-3c4919c13040/Untitled.png)

    ```
    The image shows:
    P: position of the player
    H: hitpoint of the ray on the wall
    perpWallDist: the length of this line is the value to compute now, the distance perpenducilar from the wall hit point to the camera plane instead of Euclidean distance to the player point, to avoid making straight walls look rounded.
    yDist matches what is "(mapY - posY + (1 - stepY) / 2)" in the code above, this is the y coordinate of the Euclidean distance vector, in world coordinates.
    Euclidean is the Euclidean distance from the player P to the exact hit point H. Its direction is the rayDir, but its length is all the way to the wall.
    rayDir: the direction of the ray marked "Euclidean", matching the rayDirX and rayDirY variables in the code. Note that its length |rayDir| is not 1 but slightly higher, due to how we added a value to (dirX,dirY) (the dir vector, which is normalized to 1) in the code.
    rayDirX and rayDirY: the X and Y components of rayDir, matching the rayDirX and rayDirY variables in the code.
    dir: the main player looking direction, given by dirX,dirY in the code. The length of this vector is always exactly 1. This matches the looking direction in the center of the screen, as opposed to the direction of the current ray. It is perpendicular to the camera plane, and perpWallDist is parallel to this.
    orange dotted line (may be hard to see, use CTRL+scrollwheel or CTRL+plus to zoom in a desktop browser to see it better): the value that was added to dir to get rayDir. Importantly, this is parallel to the camera plane, perpendicular to dir.
    camera plane: this is the camera plane, the line given by cameraX and cameraY, perpendicular to the main player's looking direction.

    A: point of the camera plane closest to H, the point where perpWallDist intersects with camera plane
    B: point of X-axis through player closest to H, point where yDist crosses X-axis through the player
    C: point at player position + rayDirX
    D: point at player position + rayDir.
    E: This is point D with the dir vector subtracted, in other words, E + dir = D.
    points A, B, C, D, E, H and P are used in the explanation below: they form triangles which are considered: BHP, CDP, AHP and DEP.

    And the derivation of the perpWallDist computation above then is:

    1: "(mapY - posY + (1 - stepY) / 2) / rayDirY" is "yDist / rayDirY" in the picture.
    2: Triangles PBH and PCD have the same shape but different size, so same ratios of edges
    3: Given step 2, the triangles show that the ratio yDist / rayDirY is equal to the ratio Euclidean / |rayDir|, so now we can derive perpWallDist = Euclidean / |rayDir| instead.
    4: Triangles AHP and EDP have the same shape but different size, so same ratios of edges. Length of edge ED, that is |ED|, equals length of dir, |dir|, which is 1. Similarly, |DP| equals |rayDir|.
    5: Given step 4, the triangles show that the ratio Euclidean / |rayDir| = perpWallDist / |dir| = perpWallDist / 1.
    6: Combining steps 5 and 3 shows that perpWallDist = yDist / rayDirY, the computation used in the code above

    [Thanks to Roux Morgan for helping to clarify the explanation of perpWallDist in 2020, the tutorial was lacking some information before this]
    ```

    해결: 삼각비를 이용한 공식이다.

    문제: 벽을 세우기 무섭습니다.

    해결: 다시 처음부터 시작입니다. 로데브를 적용해서 바로 벽을 세웁시다. 공부는 할 만큼 했습니다.

    - 로데브에서 벽을 세우는 과정은 절반은 이해를 했습니다. 그런데 문제가 발생해서 다 뜯어고쳐야 합니다.
    - 좌표계를 완전히 수정하는 날입니다.
    - 이제는 벽에 맞출 차례입니다. 바로 DDA의 등장.
    - [https://github.com/365kim/raycasting_tutorial](https://github.com/365kim/raycasting_tutorial)
    - 이 공식이 이해가 되지 않아 생각중입니다.

    ```
    deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
    deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
    ```

    - 음... 로데브를 읽다보니... 좌표를 완전 다르게 구현해야겠군요... 플레이어의 위치는 격자가 교차하는 곳을 좌표로 계산해서 소수로 표현해야겠습니다. 이런 망했어요.
    - 아 그리고 위 식은 이해를 했습니다. x가 1이면, 당연히 y는 y / x겠지요. (x, y)에서 x로 나누면 (1, y / x)
- 텍스쳐 적용

    생각: 텍스쳐까지 그렸으면, 이제 스프라이트와 나머지 작업만 해주면 끝납니다. 하지만 스프라이트가 가장 어려우니, 나머지 파싱이나 비트맵 부분을 해도 됩니다. 우선 다시 슬랙과 자료조사를 해 봅시다.

    생각: 코드를 분할합시다.

    문제: 텍스터 작업을 해 봅시다. 그런데 텍스쳐가 제대로 나오지 않습니다.

    해결: 복사할 때 x = -1초기화를 y 반복문 안에 넣어주어야 하는데 그러지 않았습니다.

    문제: 텍스쳐를 입혀봅시다. 근데 계속 seg가 발생합니다.

    해결: x++이 아니라... ++x를 해야죠...

- #cub3d #sprite - 1.5

    문제: 로데브 스트라이프를 다 이해하고 적용했는데 이상합니다. 코드를 적용할 때 무언가 실수한 것 같습니다.

    해결: 아직...

    ---

    문제: 파싱 도중에 다시 스프라이트로 오니 스프라이트가 그려지지 않습니다.

    해결: 파싱을 대충 해서, 맵의 col, row 값을 가져오지 못해 sprite의 개수가 0이여서 그렇습니다.

### 맵 파싱

- 맵 파싱

    문제: 맵 파싱을 시작합시다. 야매로 get_next_line로 읽고 포인터를 이동해서 파싱이 제대로 되는지 해봅시다.

    해결: 야매로 대충 파싱은 성공했습니다. 이제 다듬기만 하면 됩니다.

    ---

    문제: 맵 파싱을 어떻게 해야 할까요?

    해결: get_next_line으로 한 줄씩 읽어오고, map은 list로 작업합니다. 하지만 조건들이 꽤나 많이 있습니다.

    조건1: 공백이 여러개 들어와도 

- 맵 유효성
- 맵 해상도

    정보: 맵 해상도가 현재 해상도를 넘어가면 현재 해상도에 맞게 창을 그려야 하는데, 그 정보를 받아오는 함수가 mlx_get_screen_size입니다. 하지만 이 함수는 mlx_opengl에는 없고 mlx_mms에 있어서 결국 두 프로그램 모두 사용해야 합니다.

- 맵 테스터

    [https://github.com/humblEgo/cub3D_map_tester](https://github.com/humblEgo/cub3D_map_tester)

    [https://github.com/mlaraki/cub3D_leaks_maps_tester](https://github.com/mlaraki/cub3D_leaks_maps_tester)

### 기타

- BMP 저장

    문제: —save옵션을 주고 비트맵으로 저장해봅시다. 그러면 어떻게 접근하는게 좋을까요?

    해결: [https://dojang.io/mod/page/view.php?id=702](https://dojang.io/mod/page/view.php?id=702)이 링크를 보고 공부를 해 봅시다.

    ---

    문제: 파일을 어떻게 만들까요?

    해결: open과 close를 이용하여 파일을 만드는 법을 배웁시다.

    [https://bubble-dev.tistory.com/entry/CC-open-함수-파일-생성-읽기-쓰기](https://bubble-dev.tistory.com/entry/CC-open-%ED%95%A8%EC%88%98-%ED%8C%8C%EC%9D%BC-%EC%83%9D%EC%84%B1-%EC%9D%BD%EA%B8%B0-%EC%93%B0%EA%B8%B0)

    [https://www.it-note.kr/19](https://www.it-note.kr/19)

    [https://mong9data.tistory.com/111](https://mong9data.tistory.com/111)

    ## 6.1 cub3d bitmap

    우선 bitmap을 만들기 위해서 open과 close 함수를 사용해서 파일을 만들고 작업해야 한다.

    open의 첫 번째 인자는 파일의 이름. 두 번째 인자는 fd설정, 마지막 인수는 파일의 권한이다.

    ```c
    void	save(int *data)
    {
    	int		fd;

    	fd = open("save.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT | O_EXCL
    	, S_IRWXU | S_IRWXG | S_IRWXO);
    	bitmap_file_header(fd);
    	bitmap__header(fd);
    	close(fd);
    }
    ```

- mlx_mms적용

- 에러 처리

    문제: ./cub3d map.cub와 같이 인자를 하나만 받아야 하며, .cub 확장자로 인자가 입력되어야 합니다. .cub가 아닌 경우를 예외처리 하려면 어떻게 해야 할까요?

    해결: ft_strncmp()를 사용합시다.

### 마무리

- 노미넷 체크
- 평가항목 맞추기
- 슬랙 정리

    cub3d 하려면 아직 한참 멀었지만 raycasting이 뭔가 싶어서 유투브에 검색해보니까 이런게 나와서 공유드립니다 동영상 보니까 c로 구현하고 openCL맞나요 그거 썼다고 하는데 도움이 되실려나 모르겠네요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1594580361430500](https://42born2code.slack.com/archives/CU6MU5TB7/p1594580361430500)

    minilibx로 점 찍기를 하고 있는 중입니다. 윈도우창 크기를 500x500으로 두고 중간지점인 (250, 250)에 흰색 점을 먼저 찍고

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1595214538490500](https://42born2code.slack.com/archives/CU6MU5TB7/p1595214538490500)

    안녕하세요 cub3d 진행 하려고 이래저래 정보를 알아가고 있는 중입니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1595350286005600](https://42born2code.slack.com/archives/CU6MU5TB7/p1595350286005600)

    cub3d를 진행 하고 있는데 막힌 부분에서 도움이 필요햐여 질문드립니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1598073801008000](https://42born2code.slack.com/archives/CU6MU5TB7/p1598073801008000)

    cub3d를 xcode에서 하려고 하는데 사진과 같은 에러가 발생합니다. 혹시 원인을 아시는 분 계신가요?? (edited)

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1598769598001100](https://42born2code.slack.com/archives/CU6MU5TB7/p1598769598001100)

    혹시 cub3d에서 행렬 선언해서 처리하신 분도 계신가요? x,y따로 작업하려니 행렬을 이용하면 더 간편할 거 같은데, C에서는 행렬 처리가 쉬워보이지는 않네요.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1600302707146500](https://42born2code.slack.com/archives/CU6MU5TB7/p1600302707146500)

    cub3d에서 mlx_loop에서 segfault나는 건 보통 어떤 상황일까요? 그냥 창만 띄우고 키 입력하는 데까지는 문제가 없었는데, 레이캐스팅 집어 넣고 나니 문제가 생기네요. -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft 옵션으로 컴파일했습니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1600320657149600](https://42born2code.slack.com/archives/CU6MU5TB7/p1600320657149600)

    cub3d 하실 때 map validation 체크 다들 어떻게 하셨나요? 그래프 탐색보다 쉽고 증명된 방법이 있을까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1601641132124600](https://42born2code.slack.com/archives/CU6MU5TB7/p1601641132124600)

    cub3d를 이제 준비하고있씁니당... 궁금한게요, 우리는 맵에서 바닥과 벽의 위치를 정수로만 표현할 수 있잖아요? 그런데 어떻게 플레이어의 위치는 유리수처럼 부드럽게 슉슉 움직이는거죠..?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1602120889263600](https://42born2code.slack.com/archives/CU6MU5TB7/p1602120889263600)

    cub3d를 작성하다보면 길을 잃어버립니다. 살려주세요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603099885013500](https://42born2code.slack.com/archives/CU6MU5TB7/p1603099885013500)

    제 cub3d가 반으로 갈라져 죽어버렸습니다... 저와 같은 문제를 겪어보신 분 계실까요....

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603167046048500](https://42born2code.slack.com/archives/CU6MU5TB7/p1603167046048500)

    안녕하세요, cub3d를 하면서 랜더링을 진행 중입니다. 그런데, 동 쪽과 서 쪽은 잘 되었는 데, 남 쪽과 북 쪽의 랜더링 값이 이상합니다. 제가 printf로 남쪽의 랜더링 좌표를 찍어봤는 데 해석이 안됩니다. 이 증상에 대해서 알고 계신거나 남쪽 북쪽을 계산할 때 조심해야할 점에 대해서 조언 부탁드립니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603262261172600](https://42born2code.slack.com/archives/CU6MU5TB7/p1603262261172600)

    @minckim 님의 cub3D강의는 어디서 볼 수 있나요 여러분? (edited)

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603262723173600](https://42born2code.slack.com/archives/CU6MU5TB7/p1603262723173600)

    Factorio라는 게임 안에서 구현했다네요..

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603275497192100](https://42born2code.slack.com/archives/CU6MU5TB7/p1603275497192100)

    cub3d에서

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603371633337000](https://42born2code.slack.com/archives/CU6MU5TB7/p1603371633337000)

    혹시 리눅스 환경에서 mlx라이브러리 사용해 보신 분들 있으신가요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603491735474300](https://42born2code.slack.com/archives/CU6MU5TB7/p1603491735474300)

    s_map.map은 이중포인터구요, 다른곳에서 t_map 형식 구조체 s_map을 선언하여 초기화없이 변수로 넘겨받은 모습입니다. 저렇게 코딩을 하니 s_map->map[line_num]이 전부 널인뎅.. 어떻게 해야 메모리 주소를 할당해줄 수 있을까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603605207027900](https://42born2code.slack.com/archives/CU6MU5TB7/p1603605207027900)

    mlx_hook() 등의 함수에서 xevent 가 파라미터로 존재하는데 정확히 어떤 이벤트들이 있는지 확신하지 못해서 찝찝해하시는 분들이 있을것 같습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603605332029900](https://42born2code.slack.com/archives/CU6MU5TB7/p1603605332029900)

    [https://harm-smits.github.io/42docs/libs](https://harm-smits.github.io/42docs/libs)

    cub3d 평가 관련해서 질문 드립니다!

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603800790166300](https://42born2code.slack.com/archives/CU6MU5TB7/p1603800790166300)

    안녕하세요 cub3D를 진행중에 map 파싱 관련하여 궁금한 것이 생겼습니다. 여러분들은 map을 n * m 2차원 배열(int[][])로 구현하셨나요 아니면 각각 길이가 다른 포인터로 구성된 포인터(int **)로 구현하셨나요? 저는 두 번째 방법으로 구현중에 있는데 어떻게 구현하는 것이 좋은지 궁금합니다!

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1603980028263600](https://42born2code.slack.com/archives/CU6MU5TB7/p1603980028263600)

    cub3d minilibx 사용법을 공부중입니다... mlx_xpm_file_to_image를 이용해 이미지를 불러오는 것 까지는 문제가 없는데, mlx_put_image_to_window 함수로 출력하려고 하면 바로 세그폴트가 떠버리네요 뭐가 문제일까요...?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604114374323600](https://42born2code.slack.com/archives/CU6MU5TB7/p1604114374323600)

    큐브3d를 진행하는 중인데요, 맵에러를 탐지하는 과정에서 세그폴트가 발생하여 질문드립니다. 보기와 같이 map_dup을 생성하여 거기다 맵을 복사하는데, 맵을 복사하는 함수를 빠져나오기가 무섭게

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604396141417900](https://42born2code.slack.com/archives/CU6MU5TB7/p1604396141417900)

    Cub3d 들어가기 전에 우분투 가상머신으로 minilibx연습하려고 하는데, make를 하면 clock skew detected 오류가 나면서 종료가 됩니다. 혹시 해결방법을 아시는 분 있으신가요? 인터넷에서 touch로 시간을 맞춰주라는데 그걸 해도 계속해서 오류가 납니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604415123434000](https://42born2code.slack.com/archives/CU6MU5TB7/p1604415123434000)

    cub3d에서 맵 안에 공백이 있는 것도 유효한 맵으로 인정하셨나요? 저는 "The map must be closed/surrounded by walls, if not the program must return an error. "를 1로 둘러 싸여 있기만 하면 된다고 이해를 했는데 cub3d map tester나 다른 글들을 보면 맵 안에 공백이 있는 것도 잘못된 맵으로 처리하시더라고요.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604456130454600](https://42born2code.slack.com/archives/CU6MU5TB7/p1604456130454600)

    ㅇ ㅣ거 비밀의 방이라고 우기면 혼나나요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604475897467600](https://42born2code.slack.com/archives/CU6MU5TB7/p1604475897467600)

    mlx을 활용하는 프로젝트 (miniRT, cub3D)를 할 때 mlx.h의 norm까지 맞춰야 하는건가요? 프로젝트 폴더 안에 mlx.h가 들어가있긴 합니다...

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604665251114300](https://42born2code.slack.com/archives/CU6MU5TB7/p1604665251114300)

    cub3d 를 집에서 하려고, 과제를 git clone 했는데 자꾸 안되네요. 노트북도 동일합니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604724917136300](https://42born2code.slack.com/archives/CU6MU5TB7/p1604724917136300)

    cub3D를 mms library로 진행할 때

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604727343138400](https://42born2code.slack.com/archives/CU6MU5TB7/p1604727343138400)

    cub3d 질문있습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604817553166300](https://42born2code.slack.com/archives/CU6MU5TB7/p1604817553166300)

    큡3d하는데 높은확률로 프로그램이 터지는데.. 왜 터지는지 잘 모르겠을땐 어떻게 해야될까요? 깔끔하게 짰다고 생각했는뎅..

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604822368174000](https://42born2code.slack.com/archives/CU6MU5TB7/p1604822368174000)

    cub3D 를 보너스를 진행하면서 fork와 system("afplay ... ") 을 통해 배경음악을 넣었습니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604901616239100](https://42born2code.slack.com/archives/CU6MU5TB7/p1604901616239100)

    minilibx를 xubuntu에서 돌려보면서 공부중인데, 잘 안되는 부분이 있어서 질문드립니다. 현재 taelee님의 깃허브를 통해 예제 코드( [https://github.com/taelee42/mlx_example/blob/master/02key_handling/main.c](https://github.com/taelee42/mlx_example/blob/master/02key_handling/main.c) ) 에서 mlx_hook()을 보고 있는데, 컴파일해서 실행해보면 윈도우는 잘 뜨는데 후킹이 제대로 되지 않는지 key_press()가 실행이 되질 않습니다.(함수가 실행이 안되서 맨 마지막 printf도 안 뜹니다.)

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1604926732282700](https://42born2code.slack.com/archives/CU6MU5TB7/p1604926732282700)

    floor(1)이 0이 나오는건 어떤 경우죠...? double형 변수 a에 1을 넣었는데 (정확히 1인지는 double 형식의 특징을 몰라서 잘 모르겠지만 프린트하면 1로 나옵니당.) floor(a)가 0이 나오네요. 항상 그런것도 아니고 가끔 그래요. 심지어 이 경우에는 if(a == 1)에 넣어도 false를 뱉어요... (edited)

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605088214343600](https://42born2code.slack.com/archives/CU6MU5TB7/p1605088214343600)

    DDA 알고리즘 관련해서 질문 받아주실 분 클러스터에 계신가요? 벽과 벽 사이에 계속 저런식으로 튀어나오는 부분이 있는데 어떻게 처리할지 막막합니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605092527347200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605092527347200)

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605107883355200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605107883355200)

    [cub3d]

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605149170398300](https://42born2code.slack.com/archives/CU6MU5TB7/p1605149170398300)

    cub3D 각도기반으로 구현할 때 참고할만한 링크 몇 개 추천 좀 부탁드리겠습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605157928407300](https://42born2code.slack.com/archives/CU6MU5TB7/p1605157928407300)

    cub3d진행중에 벽이 불투명하게 나오는데 혹시 이런 현상 나타나신분 계신가요? 아무리 찾아봐도 왜 이렇게 나타나는지 모르겠네요…

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605168621427800](https://42born2code.slack.com/archives/CU6MU5TB7/p1605168621427800)

    레이캐스팅을 보면서 벡터연산에 궁금한게 있습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605249694475600](https://42born2code.slack.com/archives/CU6MU5TB7/p1605249694475600)

    (1 + 올라간 Y값의 길이의 제곱)^0.5 (1 + 늘어난 X값의 길이의 제곱)^0.5인건 알겠는데 그걸 어떻게 위의 코드로 코드로 표현했는지 이해가 안가요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605249803478300](https://42born2code.slack.com/archives/CU6MU5TB7/p1605249803478300)

    cub3d평가전에 cub3d 평가항목을 볼 수는 없을까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605283877019200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605283877019200)

    miniLibX 강좌가 있었네요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605342344041400](https://42born2code.slack.com/archives/CU6MU5TB7/p1605342344041400)

    cub3d 질문입니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605426932087900](https://42born2code.slack.com/archives/CU6MU5TB7/p1605426932087900)

    cub3d를 진행중입니다. 계산을 통해서 완성된 화면의 int* 형 이미지 버퍼를 만들었습니다. 그다음에 이 이미지를 mlx_put_image_to_window로 화면에 띄우고싶은데 바로 이 이미지 버퍼를 넣는건 안되네요. 어떻게 해야할까요? put_pixel은 너무 느려서 피하고싶네요..

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605430700098600](https://42born2code.slack.com/archives/CU6MU5TB7/p1605430700098600)

    cub3d 진행중입니당... 비트맵 파일로 저장을 하고싶은데 뭐가 잘못됐는지도 모르겠고 비트맵 파일을 열면 "파일이 손상되었거나 미리보기가 인식하지 않는 파일 포맷을 사용합니다."라고만 떠서 여기다 질문을 올립니다..ㅇ.. ㅇ...

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605532138152300](https://42born2code.slack.com/archives/CU6MU5TB7/p1605532138152300)

    cub3d를 하다가, make를 한 후 ./cub3d를 실행하면 확률적으로 뜨기도 하고 안 뜨기도 하는데, 잘 된 걸 확인하고 화면을 껐다가 다시 실행하면 Segmentation Fault가 뜨고, 또 다시 실행하면 다시 잘 나오는 기이한 현상이 발생합니다... 혹시 원인을 아시는 분 계신가요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605551922161700](https://42born2code.slack.com/archives/CU6MU5TB7/p1605551922161700)

    갑자기 든 의문인데

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605664032201900](https://42born2code.slack.com/archives/CU6MU5TB7/p1605664032201900)

    레이 캐스팅을 에서 광선의 거리에 따라 화면에 나오는 벽의 높이를 구하는 부분이 있는데 화면에 그려야 할 수직선의 높이를 구할때 시작점과 끝점을

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605665033204200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605665033204200)

    cub3d에서 errno 변수를 사용해도 될까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605680865224000](https://42born2code.slack.com/archives/CU6MU5TB7/p1605680865224000)

    cub3d에서 서브젝트 이외에 mlx관련 첨부파일이 2개 더 있는걸로 보이는데, 이 두개의 차이는 무엇인가요? 구버전과 신버전의 차이인가요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605751756248200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605751756248200)

    혹시 mlx beta버전 써서 cub짜신분들 make파일로 컴파일 할때 어떻게 하셨는지 알수있을까요? 아무리 찾아봐도 잘안되네요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605762954256800](https://42born2code.slack.com/archives/CU6MU5TB7/p1605762954256800)

    cub3d 질문이 있습니다! 맵에서 탭도 공백문자로 쳐야할까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605770264271900](https://42born2code.slack.com/archives/CU6MU5TB7/p1605770264271900)

    cub3d 공부중에 궁금한 부분이 있어 질문드립니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605790871310200](https://42born2code.slack.com/archives/CU6MU5TB7/p1605790871310200)

    레이캐스팅을 공부하면서 궁금한 점이 있습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605836059324600](https://42born2code.slack.com/archives/CU6MU5TB7/p1605836059324600)

    cub3d는 알면 알수록 어렵네요 흑흑

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605849845347500](https://42born2code.slack.com/archives/CU6MU5TB7/p1605849845347500)

    mlx관련 질문입니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605851473359400](https://42born2code.slack.com/archives/CU6MU5TB7/p1605851473359400)

    mlx_hook에 on_keypress라는 함수를 등록했을때 on_keypress의 key값이 아스키 값이라고 생각했는데

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605854110366400](https://42born2code.slack.com/archives/CU6MU5TB7/p1605854110366400)

    입출력 하드웨어의 구성에 대해서 읽다가 흥미로운 부분이 있어서 질문 올립니다.

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1605866831391900](https://42born2code.slack.com/archives/CU6MU5TB7/p1605866831391900)

    혹시라도 코로나가 지금보다 심각한 상황이 되어서 클러스터 출입이 금지된다면 cub3D 나 miniRT 같은 프로젝트들을 리눅스에서 평가받는것도 괜찮은가요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606060199045600](https://42born2code.slack.com/archives/CU6MU5TB7/p1606060199045600)

    cube3d를 진행할때.. VM머신에 MAC OS를 깔아서 진행해도 될까요 ?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606254367205700](https://42born2code.slack.com/archives/CU6MU5TB7/p1606254367205700)

    레이 캐스팅에서 벽과 바닥을 그릴때 빛의 방향을 벽을 레이캐스팅할 때보다 2배 더 많이 쓰는 이유가 무엇인가요??

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606287259215400](https://42born2code.slack.com/archives/CU6MU5TB7/p1606287259215400)

    스프라이트만 그리면 되는데... 스프라이트는 어떻게 처리하셨나요..... 흑흑

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606351140270000](https://42born2code.slack.com/archives/CU6MU5TB7/p1606351140270000)

    바닥과 천장을 레이캐스팅하는걸 계속보는중인데 한줄한줄 볼때마다 골때리네요

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606355470274400](https://42born2code.slack.com/archives/CU6MU5TB7/p1606355470274400)

    -save 옵션이있으면 첫 렌더링 이미지를 저장해야되는건 알겠는데 그 이후에 cub3d가 계속 돌아야되는건지 바로 종료되야 되는건지 알수 있을까요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606390232292100](https://42born2code.slack.com/archives/CU6MU5TB7/p1606390232292100)

    혹시 윈도우 컴퓨터에서 우분투 18.04 LTS환경에 minilibx_linux 설치하고 Xming으로 cub3d진행하신분 계신가요?

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606412583305900](https://42born2code.slack.com/archives/CU6MU5TB7/p1606412583305900)

    cub3d에서 벽과 천장을 레이캐스팅하고 텍스쳐를 입히는루프에서 의문점들이 있습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606446820336400](https://42born2code.slack.com/archives/CU6MU5TB7/p1606446820336400)

    cub3d 로데브 코드를 보면서 공부중인데 혹시 여기서 texPos가 식이 저렇게 써진 이유가 있나요?? 어떤 변수인지 모르겠어서 계산해보는데 늘 시작값은 0이 나오는거 같아서요 ㅠㅠ 0으로 바꿔서 써도 잘돌아가더라구요.. 이후에 값이 다르게나오는건지 0으로 선언만 해도 되는건지 궁금합니다..

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606620828412800](https://42born2code.slack.com/archives/CU6MU5TB7/p1606620828412800)

    cub3d 에서 인자를 여러가지 준 경우 에러로 처리하고 프로그램을 종료하는것이 맞나요??

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606656640422100](https://42born2code.slack.com/archives/CU6MU5TB7/p1606656640422100)

    로데브 튜토리얼을 보고나서 mlx예시를 보면서 시작할려고 하자마자 문제가 생겼습니다

    [https://42born2code.slack.com/archives/CU6MU5TB7/p1606699352458500](https://42born2code.slack.com/archives/CU6MU5TB7/p1606699352458500)

- 참고 자료

    [https://github.com/taelee42/mlx_example](https://github.com/taelee42/mlx_example)

    [https://github.com/sungyongcho/ii2r](https://github.com/sungyongcho/ii2r)

    [https://lodev.org/cgtutor/raycasting.html](https://lodev.org/cgtutor/raycasting.html)

    [https://github.com/365kim/raycasting_tutorial](https://github.com/365kim/raycasting_tutorial)

    [https://github.com/minckim0/cub3d_lect](https://github.com/minckim0/cub3d_lect)

    [https://github.com/l-yohai/cub3d](https://github.com/l-yohai/cub3d)

    [https://42kchoi.tistory.com/category/Code 42/miniLibX%2C 3서클](https://42kchoi.tistory.com/category/Code%2042/miniLibX%2C%203%EC%84%9C%ED%81%B4)

    [https://github.com/ChoiKanghun/Cub3d_practice](https://github.com/ChoiKanghun/Cub3d_practice)

    [https://velog.io/@dnstlr2933/cub3d-28y5k0ar](https://velog.io/@dnstlr2933/cub3d-28y5k0ar)

    [https://yechoi.tistory.com/16](https://yechoi.tistory.com/16)

    [https://github.com/humblEgo/cub3D_map_tester](https://github.com/humblEgo/cub3D_map_tester)

    [https://github.com/mlaraki/cub3D_leaks_maps_tester](https://github.com/mlaraki/cub3D_leaks_maps_tester)