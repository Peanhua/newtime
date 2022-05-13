/*
  Newtime
  Copyright (C) 2022  Steve Joni Yrjänä <joniyrjana@gmail.com>
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Complete license can be found in the LICENSE file.
*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


static _Bool        ParseArgs(int argc, char * argv[]);
static void         PrintUsage();
static const char * GetPostfix();


static const char * postfixes[] =
  {
    "EAM", // Early AM
    "LAM", // Late PM
    "EPM", // Early PM
    "LPM"  // Late PM
  };


static char *       program_name = "newtime";
static unsigned int source_time  = 0;


int main(int argc, char * argv[])
{
  if(!ParseArgs(argc, argv))
    {
      PrintUsage();
      return EXIT_FAILURE;
    }

  printf("%u %s\n", source_time % 6, GetPostfix());

  return EXIT_SUCCESS;
}



static _Bool ParseArgs(int argc, char * argv[])
{
  _Bool rv = false;

  if(argc > 0)
    program_name = argv[0];

  if(argc == 2)
    {
      char * rest;
      source_time = strtoul(argv[1], &rest, 0);
      if(source_time < 24 && *rest == '\0')
        rv = true;
      else
        fprintf(stderr, "%s: Error, failed to parse source time argument '%s', valid value range is [0,23].\n", program_name, argv[1]);
    }
  else
    fprintf(stderr, "%s: Error, incorrect number of arguments.\n", program_name);

  return rv;
}


static void PrintUsage()
{
  printf("Usage: %s <hours>\n", program_name);
  printf("  <hours>  The input hours in range [0,23].\n");
}


static const char * GetPostfix()
{
  assert(source_time < 24);
  return postfixes[source_time / 6];
}

