# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 11:48:30 by cchen             #+#    #+#              #
#    Updated: 2021/12/14 15:41:04 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOGSPHERE=$(ls | sed -n '/intra-uuid/p')

rm -rf ./${VOGSPHERE}/*
cp ./$REPO_NAME/author ./${VOGSPHERE}
cp ./$REPO_NAME/src/get_next_line.c ./${VOGSPHERE}
cp ./$REPO_NAME/src/includes/get_next_line.h ./${VOGSPHERE}
cp -rp ./$REPO_NAME/src/libft ./${VOGSPHERE}/libft
