/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:07:15 by emsoares          #+#    #+#             */
/*   Updated: 2022/11/16 11:54:00 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
       The memcpy() function copies n bytes from memory area src to
       memory area dest.  The memory areas must not overlap.  
       The memcpy() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pt_des;
	unsigned char		*pt_src;
	size_t				i;

	pt_des = (unsigned char *)dest;
	pt_src = (unsigned char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		pt_des[i] = pt_src[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int main (void) 
{
  char src[] = "HELLO";
   ft_memcpy(src+1, src, 2);
  printf("After memcpy dest = %s\n", src);
   
  return(0);
}*/