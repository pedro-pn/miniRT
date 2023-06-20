/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:29:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 10:31:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_parser(t_parser *parser)
{
	ft_lstclear(&parser->faces, clean_faces);
	free(parser->vertices);
	parser->vertices = NULL;
}
