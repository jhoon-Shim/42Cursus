# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 11:21:09 by jshim             #+#    #+#              #
#    Updated: 2025/11/07 12:28:32 by jshim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c -Wall -Wextra -Werror *.c
ar -rcs libft.a *.o

# ar -rcs = ar rc + ranlib 

# gcc -Wall -Wextra -Werror -c *.c
# ar rc libft.a *.o
# ranlib libft.a