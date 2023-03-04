# A Little Valentine - Find your better half!

*A Little Valentine is a 2D game.
You need to collect hearts while finding your love.
Be careful! As soon as your heart breaks, the game is over.
Don't allow that anyone breaks your heart and find your better half!*

> ## “The sun doesn't always shine in life, but we can share the umbrella and survive the storm together.”

<a name="0"></a>
# [Table of content](#0)
- [Introduction to the map and your role as a player](#1)
- [Play A Little Valentine and find your love](#2)
- [Requirements for the map](#3)
- [Benefits of A Little Valentine](#4)
- [Installation](#5)
- [Implementation](#6)
- [Examples](#7)
- [Deinstallation](#8)

<a name="1"></a>
# [Introduction to the map and your role as a player](#1)
Note that I included [MiniLibX](https://github.com/42Paris/minilibx-linux) as a graphics library, and I used my own [libft](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/libft) for [printf](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/libft/ft_printf.c), [memset](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/libft/ft_memset.c) and [strncmp](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/libft/ft_strncmp.c). The libft also contains the function [get_next_line](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/libft/get_next_line_bonus) to read from a file descriptor. 

|Character|Description|Image|Significance|
|:--:|:--------:|:----:|:----:|
|0|Empty Space|empty.xpm|**You may step on the very ground of the map.**|
|1|Wall|wall.xpm|**You cannot move through the walls of the map.**|
|C|Collectible|heart.xpm|**You need to collect the displayed hearts. If you have collected all of them you can come together with your love.**|
|E|Exit|man.xpm|**You want to find your love. But you will only become a couple if you have collected all the displayed hearts.**|
|P|Player|woman.xpm|**You are the player. Depending on the map you choose you will start at different positions.**|
|R|Rival|broken_heart.xpm|**You need to take care of yourself. Do not step onto those spaces! As soon as you do your heart will break and the game is over.**|

<a name="2"></a>
# [Play A Little Valentine and find your love](#2)
|Key code|Description|Function|
|:--:|:--------:|:--------:|
|123|Left arrow|**Moves left**|
|124|Right arrow|**Moves right**|
|125|Down arrow|**Moves down**|
|126|Up arrow|**Moves up**|
|48|Tab |**Displayes how many hearts you still need to collect**|
|53|Escape|**Closes the window and terminates the game**|

<a name="3"></a>
# [Requirements for the map](#3)
- [x] It must be **rectangular**.
- [x] It must be **surrounded by walls**.
- [x] It must contain exactly **one exit**.
- [x] It must contain exactly **one starting position**.
- [x] It must contain **at least one collectible**.

<a name="4"></a>
# [Benefits of A Little Valentine](#4)

-  **Install and implement easily**

     - [x] You can easily implement *A Little Valentine* as explained in [Installation](#3) and [Implementation](#4).
-  **Customize the existing maps**

     - [x] You can easily customize the existing maps. The program will check whether your map is valid and meets the [requirements](#5).
-  **Create your own map easily**

      - [x] You can easily modify the content of the directory [maps](https://github.com/lspohle/PRIVATE_a_little_valentine/tree/main/maps) and create your own map.
-  **Adjust the colors or the content of the output in the shell**

      - [x] You may easily adjust the colors of the output in the shell by modifying the constants of the colors in [a_little_valentine.h](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/srcs/a_little_valentine.h). If you want to adjust the content of the output, immerse yourself in [display_output.c](https://github.com/lspohle/PRIVATE_a_little_valentine/blob/main/srcs/display_output.c).
-  **Works on all devices with macOS**

      - [x] *A Little Valentine* works on the operating system macOS. You do not need to install anything. All necessary installations are either pre-installed on macOS or included in the repository of *A Little Valentine*.

<a name="5"></a>
# [Installation](#5)
- Install *A Little Valentine* by cloning the current repository, and creating an alias for your little valentine.
      
      cd ~ && git clone git@github.com:lspohle/PRIVATE_a_little_valentine.git && cd PRIVATE_a_little_valentine/srcs && bash script.sh
      make -s

<a name="6"></a>
# [Implementation](#6)
- Ready to challenge youself? Find your love! 
Run the following command whenever and wherever you wish to play *A Little Valentine*. Select a different map by replacing `map2.ber` by the map of your choice. Take a look at the them in [maps](https://github.com/lspohle/PRIVATE_a_little_valentine/tree/main/maps). 

       alv ../maps/map2.ber

<a name="7"></a>
# [Examples](#7)

https://user-images.githubusercontent.com/121381385/222758862-d51462eb-f52b-41c3-b117-ff9856bee753.mov

https://user-images.githubusercontent.com/121381385/222758107-31ea796a-9955-430b-9f99-fc7f9fb6a129.mov

<a name="7"></a>
# [Deinstallation](#8)
- Deinstall *A Little Valentine* from your device.
      
      cd ~ && rm -rf PRIVATE_a_little_valentine
- Enter your ZSH configuration file, and remove the formerly created alias `alv` from your ZSH configuration file.

      nano ~/.zshrc

