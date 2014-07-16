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
#include <srcsax_handler_test.hpp>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <cassert>

/**
 * read_callback
 * @param context the context to read from
 * @param buffer the buffer to read into
 * @param len the number of bytes to read
 *
 * FILE read callback for testing io.
 *
 * @returns the number of bytes read.
 */
int read_callback(void * context, char * buffer, int len) {

    return (int)fread(buffer, 1, len, (FILE *)context);

}

/**
 * close_callback
 * @param context the context to read from
 *
 * FILE close callback for testing io.
 *
 * @returns 0 on success EOF otherwise.
 */
int close_callback(void * context) {

    return fclose((FILE *)context);

}

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
    assert(context->libxml2_context != 0);

    srcsax_free_context(context);
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
    assert(context->libxml2_context != 0);

    srcsax_free_context(context);
    close(fd);

  }

  {

    srcsax_context * context = srcsax_create_context_fd(-1, "UTF-8");

    assert(context == 0);

  }

  /*
    srcsax_create_context_io
  */
  {

    FILE * file = fopen(__FILE__, "r");
    srcsax_context * context = srcsax_create_context_io((void *)file, read_callback, close_callback, "UTF-8");

    assert(context->data == 0);
    assert(context->handler == 0);
    assert(context->srcsax_error == 0);
    assert(context->is_archive == 0);
    assert(context->unit_count == 0);
    assert(context->encoding == 0);
    assert(context->input != 0);
    assert(context->libxml2_context != 0);

    srcsax_free_context(context);

  }

  {

    FILE * file = fopen(__FILE__, "r");
    srcsax_context * context = srcsax_create_context_io((void *)file, read_callback, close_callback, "ISO-8859-1");

    assert(context->data == 0);
    assert(context->handler == 0);
    assert(context->srcsax_error == 0);
    assert(context->is_archive == 0);
    assert(context->unit_count == 0);
    assert(context->encoding == 0);
    assert(context->input != 0);
    assert(context->libxml2_context != 0);

    srcsax_free_context(context);

  }

  {

    FILE * file = fopen(__FILE__, "r");
    srcsax_context * context = srcsax_create_context_io((void *)file, read_callback, close_callback, 0);

    assert(context->data == 0);
    assert(context->handler == 0);
    assert(context->srcsax_error == 0);
    assert(context->is_archive == 0);
    assert(context->unit_count == 0);
    assert(context->encoding == 0);
    assert(context->input != 0);
    assert(context->libxml2_context != 0);

    srcsax_free_context(context);

  }

  {

    FILE * file = fopen(__FILE__, "r");
    srcsax_context * context = srcsax_create_context_io((void *)file, 0, close_callback, "UTF-8");

    assert(context == 0);

  }

  {

    srcsax_context * context = srcsax_create_context_io(0, read_callback, close_callback, "UTF-8");

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
  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;
    context->handler = &handler;

    assert(srcsax_parse(context) == 0);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;
    context->handler = &handler;

    assert(srcsax_parse(context) == -1);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;
    context->handler = &handler;

    assert(srcsax_parse(0) == -1);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;

    assert(srcsax_parse(context) == -1);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;
    context->handler = 0;

    assert(srcsax_parse(context) == -1);

    srcsax_free_context(context);

  }

  /*
    srcsax_parse_handler
   */
  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;

    assert(srcsax_parse_handler(context, &handler) == 0);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;

    assert(srcsax_parse_handler(context, &handler) == -1);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;

    assert(srcsax_parse_handler(0, &handler) == -1);

    srcsax_free_context(context);

  }

  {

    srcsax_handler_test data;

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;

    assert(srcsax_parse_handler(context, 0) == -1);

    srcsax_free_context(context);

  }

   /*
    srcsax_stop_parse
   */
  {

    srcsax_handler_test data;
    srcsax_handler handler = srcsax_handler_test::factory();

    const char * srcml_buffer = "<unit/>";

    srcsax_context * context = srcsax_create_context_memory(srcml_buffer, strlen(srcml_buffer), "UTF-8");
    context->data = &data;
    context->handler = &handler;

    srcsax_stop_parser(context);

    srcsax_free_context(context);

  }

  return 0;

}
