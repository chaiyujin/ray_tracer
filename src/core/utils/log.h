/* -----------------------------
* File   : log.h
* Author : yuki Chai
* Created: 2017.03.29
* Project: yuki
*/

#pragma once
# include <stdio.h>
# include <stdarg.h>
# include <vector>

namespace yuki {
	enum LOG_LEVEL {
		NONE = 0,
		NOTICE = 1,
		DEBUG = 2,
	};

#ifndef RUNTIME_LOG_LEVEL
#ifdef NDEBUG
#define RUNTIME_LOG_LEVEL yuki::LOG_LEVEL::NOTICE
#else
#define RUNTIME_LOG_LEVEL yuki::LOG_LEVEL::DEBUG
#endif
#endif

#define LOG(fmt, ...) \
	if (yuki::LOG_LEVEL::NOTICE <= RUNTIME_LOG_LEVEL) {\
		printf("[LOG] "); printf(fmt, ##__VA_ARGS__);\
	}
#define DEBUG(fmt, ...) \
	if (yuki::LOG_LEVEL::DEBUG <= RUNTIME_LOG_LEVEL) {\
		printf("[DEBUG] "); printf(fmt, ##__VA_ARGS__);\
	}
#define ERROR(fmt, ...) do {\
	printf("Error in [%s] (line: %d) : ", __FUNCTION__, __LINE__);\
	printf(fmt, ##__VA_ARGS__); } while (0);
#define ERROR_EXIT(fmt, ...) do {\
	printf("Error in [%s] (line: %d) : ", __FUNCTION__, __LINE__);\
	printf(fmt, ##__VA_ARGS__);\
	system("pause");exit(1); } while (0);
#define CHECK(assertion) do {\
		bool flag = assertion;\
		if (!flag) {\
			printf("Error in [%s] (line: %d) : CHECK fail.\n", __FUNCTION__, __LINE__);\
			system("pause");exit(1);\
		}\
	} while (0);
}


//namespace yuki {
//	enum LOGLevel {
//		ignore = 0,
//		error = 1,
//		warning = 2,
//		debug = 3,
//		log = 4,
//		always = 5
//	};
//	class LOG {
//	private:
//		#ifdef NDEBUG
//		LOGLevel _runtime_level = debug;
//		#else
//		LOGLevel _runtime_level = log;
//		#endif
//		char *_level_chars[6] = {
//			"", "[error] ", "[warning] ", "[debug]", "[log] ", "[always] "
//		};
//		std::vector<FILE *> _log_files;
//		LOGLevel _get_level_from_name(const char * level_name) {
//			if (strcmp(level_name, "error")) {
//				return error;
//			}
//			else if (strcmp(level_name, "warning")) {
//
//			}
//		};
//	public:
//		LOG() {
//			_log_files.push_back(stdout);
//		}
//		~LOG() {
//			// close all log files except stdout
//			for (size_t i = 1; i < _log_files.size(); ++i) {
//				fclose(_log_files[i]);
//			}
//		}
//		void print(const char * fmt, ...) {
//			if (true) {
//				// printf
//				va_list args;
//				va_start(args, fmt);
//				for (size_t i = 0; i < _log_files.size(); ++i) {
//					vfprintf(_log_files[i], fmt, args);
//					fflush(_log_files[i]);
//				}
//				va_end(args);
//			}
//		}
//		void print(LOGLevel level, const char * fmt, ...) {
//			if (level <= _runtime_level && level > ignore) {
//				// print level info
//				for (size_t i = 0; i < _log_files.size(); ++i) {
//					fprintf(_log_files[i], _level_chars[(int)level]);
//				}
//				// printf
//				va_list args;
//				va_start(args, fmt);
//				for (size_t i = 0; i < _log_files.size(); ++i) {
//					vfprintf(_log_files[i], fmt, args);
//					fflush(_log_files[i]);
//				}
//				va_end(args);
//			}
//		}
//	};
//}
