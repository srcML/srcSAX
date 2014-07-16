/**
 * @file test_srcsax.cpp
 *
 * @copyright Copyright (C) 2014  SDML (www.srcML.org)
 *
 * The srcML Toolkit is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The srcML Toolkit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the srcML Toolkit; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <srcsax.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <cassert>

/**
 * main
 *
 * Test the srcsax functions.
 *
 * @returns 0 on success.
 */
int main() {

/*
  srcsax_create_context_filename
*/
{

  srcsax_context * context = srcsax_create_context_filename(__FILE__, "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  srcsax_context * context = srcsax_create_context_filename(__FILE__, "ISO-8859-1");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  srcsax_context * context = srcsax_create_context_filename(__FILE__, 0);

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  srcsax_context * context = srcsax_create_context_filename(0, "UTF-8");

  assert(context == 0);

}

{

  srcsax_context * context = srcsax_create_context_filename("foobar", "UTF-8");

  assert(context == 0);

}

/*
  srcsax_create_context_memory
*/
{

  const char * srcml_buffer = "<unit/>";

  srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  const char * srcml_buffer = "<unit/>";

  srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "ISO-8859-1");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  const char * srcml_buffer = "<unit/>";

  srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), 0);

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);

}

{

  const char * srcml_buffer = "<unit/>";

  srcsax_context * context = srcsax_create_context_memory(0, strlen(srcml_buffer), "UTF-8");

  assert(context == 0);

}

{

  const char * srcml_buffer = "<unit/>";

  srcsax_context * context = srcsax_create_context_memory(srcml_buffer, 0, "UTF-8");

  assert(context == 0);

}

/*
  srcsax_create_context_FILE
*/
{

  FILE * file = fopen(__FILE__, "r");
  srcsax_context * context = srcsax_create_context_FILE(file, "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  fclose(file);

}

{

  FILE * file = fopen(__FILE__, "r");
  srcsax_context * context = srcsax_create_context_FILE(file, "ISO-8859-1");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  fclose(file);

}

{

  FILE * file = fopen(__FILE__, "r");
  srcsax_context * context = srcsax_create_context_FILE(file, 0);

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  fclose(file);

}

{

  FILE * file = fopen(__FILE__, "a");
  srcsax_context * context = srcsax_create_context_FILE(file, "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  fclose(file);

}

{

  srcsax_context * context = srcsax_create_context_FILE(0, "UTF-8");

  assert(context == 0);

}

/*
  srcsax_create_context_fd
*/
{

  int fd = open(__FILE__, O_RDONLY);
  srcsax_context * context = srcsax_create_context_fd(fd, "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  close(fd);

}

{

  int fd = open(__FILE__, O_RDONLY);
  srcsax_context * context = srcsax_create_context_fd(fd, "ISO-8859-1");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  close(fd);

}

{

  int fd = open(__FILE__, O_RDONLY);
  srcsax_context * context = srcsax_create_context_fd(fd, 0);

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  srcsax_free_context(context);
  close(fd);

}

{

  int fd = open(__FILE__, O_WRONLY | O_APPEND);
  srcsax_context * context = srcsax_create_context_fd(fd, "UTF-8");

  assert(context->data == 0);
  assert(context->handler == 0);
  assert(context->srcsax_error == 0);
  assert(context->is_archive == 0);
  assert(context->unit_count == 0);
  assert(context->encoding == 0);
  assert(context->input != 0);
  assert(context->pop_input != 0);
  assert(context->libxml2_context != 0);

  close(fd);

}

{

  srcsax_context * context = srcsax_create_context_fd(-1, "UTF-8");

  assert(context == 0);

}

/*
  srcsax_free_context
 */

{

  srcsax_free_context(0);

}

/*
  srcsax_parse
 */

 /*
  srcsax_stop_parse
 */

  return 0;

}
