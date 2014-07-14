
typedef void (*start_document_t)();
typedef void (*end_document_t)();
typedef void (*start_function_t(const std::string & name, const std::string & return_type, const std::vector<declaration> & parameter_list, bool is_decl));
typedef void (*start_element_ns_t(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
typedef void (*end_root_t(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));
typedef void (*end_unit_t(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));
typedef void (*end_function_t());
typedef void (*end_element_ns_t(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));
typedef void (*characters_root_t(const xmlChar * ch, int len));
typedef void (*characters_unit_t(const xmlChar * ch, int len));
typedef void (*comment_t(const xmlChar * value));
typedef void (*cdata_block_t(const xmlChar * value, int len));
typedef void (*processing_instruction_t(const xmlChar * target, const xmlChar * data));
