idf_component_register(SRCS "transport.c"
                            "transport_ssl.c"
                            "transport_ws.c"
                            "transport_utils.c"
                    INCLUDE_DIRS "include"
                    PRIV_INCLUDE_DIRS "private_include"
                    REQUIRES esp-tls)
