#!/bin/zsh

gccsafe -w -I $git/seoul42_project/ft_printf -L $git/seoul42_project/ft_printf -lftprintf 00_playground.c -D MPRIN="printf"
