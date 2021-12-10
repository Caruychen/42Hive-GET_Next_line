# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 11:48:30 by cchen             #+#    #+#              #
#    Updated: 2021/12/10 12:52:28 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOGSPHERE=$(ls | sed -n '/intra-uuid/p')

rm -rf ./${VOGSPHERE}/*
cp ./$REPO_NAME/author ./${VOGSPHERE}
cp ./$REPO_NAME/src/* ./${VOGSPHERE}
cp -R ./$REPO_NAME/libft ./${VOGSPHERE}/libft
