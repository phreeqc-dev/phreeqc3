#ifndef NPP
#ifdef DOS
#include <windows.h>
#endif
#endif
#include "Phreeqc.h"

#include "NameDouble.h"
#include "Solution.h"
#include "Reaction.h"
#include "PPassemblage.h"
#include "Exchange.h"
#include "Surface.h"
#include "GasPhase.h"
#include "SSassemblage.h"
#include "cxxKinetics.h"
//#include <sys/signal.h>
//#include <fenv.h>

#if defined(PHREEQCI_GUI)
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

/* ----------------------------------------------------------------------
 *   MAIN
 * ---------------------------------------------------------------------- */
int
main(int argc, char *argv[])
/*
 *   Main program for PHREEQC
 */
{

  // check for floating point exceptions on Linux
  // feenableexcept(FE_DIVBYZERO|FE_INVALID|FE_OVERFLOW|FE_UNDERFLOW);
//#define WIN32_MEMORY_DEBUG
#if defined(WIN32_MEMORY_DEBUG)
	int tmpDbgFlag;

	/*
	 * Set the debug-heap flag to keep freed blocks in the
	 * heap's linked list - This will allow us to catch any
	 * inadvertent use of freed memory
	 */
#ifdef SKIP
	// Send messages (leaks) to stderr
    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDERR );
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDERR );
    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
#endif
	tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	//tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
	///tmpDbgFlag |= _CRTDBG_CHECK_ALWAYS_DF;
	_CrtSetDbgFlag(tmpDbgFlag);
	//_crtBreakAlloc = 31195;
#endif
#ifdef SKIP
//Set the x86 floating-point control word according to what
//exceptions you want to trap.
_clearfp(); //Always call _clearfp before setting the control
            //word
//Because the second parameter in the following call is 0, it
//only returns the floating-point control word
unsigned int cw = _controlfp(0, 0); //Get the default control
                                    //word
//Set the exception masks off for exceptions that you want to
//trap.  When a mask bit is set, the corresponding floating-point
//exception is //blocked from being generating.
cw &=~(EM_OVERFLOW|EM_UNDERFLOW|EM_ZERODIVIDE|
       EM_DENORMAL|EM_INVALID);
//For any bit in the second parameter (mask) that is 1, the
//corresponding bit in the first parameter is used to update
//the control word.
unsigned int cwOriginal = _controlfp(cw, MCW_EM); //Set it.
                            //MCW_EM is defined in float.h.
                            //Restore the original value when done:
                            //_controlfp(cwOriginal, MCW_EM);
#endif
	Phreeqc phreeqc_instance;
	return phreeqc_instance.main_method(argc, argv);
}
//#define TEST_COPY
#ifdef TEST_COPY
int Phreeqc::
main_method(int argc, char *argv[])
/*
 *   Main program for PHREEQC
 */
{

	int errors;
	std::istream *db_cookie = NULL;
	std::istream *input_cookie = NULL;
#if defined(WIN32_MEMORY_DEBUG)
	int tmpDbgFlag;

	/*
	 * Set the debug-heap flag to keep freed blocks in the
	 * heap's linked list - This will allow us to catch any
	 * inadvertent use of freed memory
	 */
	tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	//tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
	///tmpDbgFlag |= _CRTDBG_CHECK_ALWAYS_DF;
	_CrtSetDbgFlag(tmpDbgFlag);
	//_crtBreakAlloc = 9482;
#endif

	phast = FALSE;
/*
 *   Open input/output files
 */
	errors = process_file_names(argc, argv, &db_cookie, &input_cookie, TRUE);
	if (errors != 0)
	{
		return errors;
	}
#ifdef NPP
#ifdef DOS
	write_banner();
#endif
#else
#ifndef NO_UTF8_ENCODING
#ifdef DOS
	SetConsoleOutputCP(CP_UTF8);
#endif
	write_banner();
#endif
#endif

/*
 *   Initialize arrays
 */
	errors = do_initialize();
	if (errors != 0)
	{
		return errors;
	}
/*
 *   Load database into memory
 */
	this->phrq_io->push_istream(db_cookie);
	errors = read_database();
	this->phrq_io->clear_istream();

	if (errors != 0)
	{
		return errors;
	}
	Phreeqc MyCopy = *this;
	this->clean_up();
	// this->init();
	// this->initialize();
/*
 *   Read input data for simulation
 */

	MyCopy.phrq_io->push_istream(input_cookie);
	errors = MyCopy.run_simulations();

	//Phreeqc mycopy(*this);
	MyCopy.phrq_io->clear_istream();

	if (errors != 0)
	{
		return errors;
	}
/*
 *   Display successful status
 */
	pr.headings = TRUE;
	// errors = do_status();
	if (errors != 0)
	{
		return errors;
	}
	return 0;
}
#else
int Phreeqc::
main_method(int argc, char *argv[])
/*
 *   Main program for PHREEQC
 */
{

	int errors;
	std::istream *db_cookie = NULL;
	std::istream *input_cookie = NULL;
#if defined(WIN32_MEMORY_DEBUG)
	int tmpDbgFlag;

	/*
	 * Set the debug-heap flag to keep freed blocks in the
	 * heap's linked list - This will allow us to catch any
	 * inadvertent use of freed memory
	 */
	tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	//tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
	///tmpDbgFlag |= _CRTDBG_CHECK_ALWAYS_DF;
	_CrtSetDbgFlag(tmpDbgFlag);
	//_crtBreakAlloc = 9482;
#endif
	try
	{
		phast = FALSE;
		/*
		*   Open input/output files
		*/
		errors = process_file_names(argc, argv, &db_cookie, &input_cookie, TRUE);
		if (errors != 0)
		{
			return errors;
		}
#ifdef NPP
#ifdef DOS
		//SetConsoleOutputCP(CP_UTF8);
		write_banner();
#endif
#else
#ifndef NO_UTF8_ENCODING
#ifdef DOS
		SetConsoleOutputCP(CP_UTF8);
#endif
		write_banner();
#endif
#endif

		/*
		*   Initialize arrays
		*/
		errors = do_initialize();
		if (errors != 0)
		{
			return errors;
		}
		/*
		*   Load database into memory
		*/
		this->phrq_io->push_istream(db_cookie);
		errors = read_database();
		this->phrq_io->clear_istream();

		if (errors != 0)
		{
			return errors;
		}

		/*
		*   Read input data for simulation
		*/

		this->phrq_io->push_istream(input_cookie);
		errors = run_simulations();

		//Phreeqc mycopy(*this);
		this->phrq_io->clear_istream();

		if (errors != 0)
		{
			return errors;
		}
		/*
		*   Display successful status
		*/
		pr.headings = TRUE;
		errors = do_status();
		if (errors != 0)
		{
			return errors;
		}
	}
	catch (...)
	{
		int e = get_input_errors();
		std::cerr << "Unhandled exception in PHREEQC." << std::endl;
		if (e > 0)
		{
			return e;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
#endif //TEST_COPY
/* ---------------------------------------------------------------------- */
int Phreeqc::
write_banner(void)
/* ---------------------------------------------------------------------- */
{
#ifdef TESTING
	return OK;
#endif
#ifndef NO_UTF8_ENCODING
	char buffer[80];
	int len, indent;
	screen_msg("               ____________________________________________\n");
	screen_msg("              |                                            |\n");
	/* version */
	len = snprintf(buffer, sizeof(buffer), "* PHREEQC_%s *", "3.9.1");
	indent = (44 - len) / 2;
	screen_msg(sformatf("%14c|%*c%s%*c|\n", ' ', indent, ' ', buffer,
			   44 - indent - len, ' '));
	screen_msg("              |                                            |\n");
	screen_msg("              |      A hydrogeochemical transport model    |\n");
	screen_msg("              |                                            |\n");
	screen_msg("              |                    by                      |\n");
	screen_msg("              |       D.L. Parkhurst and C.A.J. Appelo     |\n");
	screen_msg("              |                                            |\n");
	/* date */
	len = snprintf(buffer, sizeof(buffer), "%s", "September 23, 2026");
	indent = (44 - len) / 2;
	screen_msg(sformatf("%14c|%*c%s%*c|\n", ' ', indent, ' ', buffer,
			   44 - indent - len, ' '));
	screen_msg("              |____________________________________________|\n\n");
#endif
	return 0;
}

/* ---------------------------------------------------------------------- */
int Phreeqc::
process_file_names(int argc, char *argv[], std::istream **db_cookie,
				   std::istream **input_cookie, int log)
/* ---------------------------------------------------------------------- */
{
	std::string token, default_name;
	std::string query;
	std::string in_file, out_file, db_file;
	char *env_ptr;
	const char* cptr;
/*
 *   Prepare error handling
 */
	try {
		if (phrq_io == NULL)
		{
			std::cerr << "No PHRQ_io output handler defined in process_file_names" << "\n";
		}
/*
 *   Prep for get_line
 */
		max_line = MAX_LINE;
		space((void **) ((void *) &line), INIT, &max_line, sizeof(char));
		space((void **) ((void *) &line_save), INIT, &max_line, sizeof(char));
/*
 *   Open error ostream
 */
		if (argc > 4)
		{
			if (!phrq_io->error_open(argv[4]))
			{
				error_string = sformatf( "Error opening file, %s.", argv[4]);
				warning_msg(error_string);
			}
		}
		else
		{
			phrq_io->error_open(NULL);
		}
/*
 *   Open user-input file
 */
		query = "Name of input file?";
		std::ifstream * local_input_stream = NULL;
		if (argc <= 1)
		{
			default_name.clear();
			local_input_stream = open_input_stream(query, default_name, std::ios_base::in, false);
		}
		else
		{
			default_name = argv[1];
			local_input_stream = open_input_stream(query, default_name, std::ios_base::in, true);
		}
		screen_msg(sformatf("Input file: %s\n\n", default_name.c_str()));
		in_file = default_name;
/*
 *   Open file for output
 */
		query = "Name of output file?";
		cptr = default_name.c_str();
		copy_token(token, &cptr);
		token = default_name;
		token.append(".out");
		std::ofstream * local_output_stream = NULL;
		if (argc <= 1)
		{
			local_output_stream = open_output_stream(query, token, std::ios_base::out, false);
		}
		else if (argc == 2)
		{
			local_output_stream = open_output_stream(query, token, std::ios_base::out, true);
		}
		else if (argc >= 3)
		{
			token = argv[2];
			local_output_stream = open_output_stream(query, token, std::ios_base::out, true);
		}
		screen_msg(sformatf("Output file: %s\n\n", token.c_str()));
		out_file = token;
		phrq_io->Set_output_ostream(local_output_stream);
/*
 *   Open log file
 */
		if (log == TRUE)
		{
			if (!phrq_io->log_open("phreeqc.log"))
			{
				error_msg("Cannot open log file, phreeqc.log.", STOP);
			}
		}
/*
 *  Read input file for DATABASE keyword
 */
		if (local_input_stream->is_open())
		{
			phrq_io->push_istream(local_input_stream);
			if (get_line() == KEYWORD)
			{
				cptr = line;
				copy_token(token, &cptr);
				if (strcmp_nocase(token.c_str(), "database") == 0)
				{
					user_database = cptr;
					string_trim(user_database);
					if (user_database.size() == 0)
					{
						warning_msg("DATABASE file name is missing; default database will be used.");
					}
				}
			}
			phrq_io->pop_istream();
		}
		else
		{
			delete local_input_stream;
			error_string = sformatf( "Error opening file, %s.", in_file.c_str());
			error_msg(error_string, STOP);
		}

/*
 *   Open data base
 */
		query = "Name of database file?";
		env_ptr = getenv("PHREEQC_DATABASE");
		if (user_database.size() > 0)
		{
			token = user_database;
		}
		else if (env_ptr != NULL)
		{
			token = env_ptr;
		}
		else
		{
			token = default_data_base;
		}

		std::ifstream * local_database_file = NULL;
		if (argc <= 1)
		{
			local_database_file = open_input_stream(query, token, std::ios_base::in, false);
		}
		else if (argc < 4)
		{
			local_database_file = open_input_stream(query, token, std::ios_base::in, true);
		}
		else if (argc >= 4)
		{
			if (user_database.size() == 0)
			{
				token = argv[3];
			}
			else
			{
#ifndef PHREEQCI_GUI
				warning_msg	("Database file from DATABASE keyword is used; command line argument ignored.");
#endif
			}
			local_database_file = open_input_stream(query, token, std::ios_base::in, true);
		}
		local_database_file->close();
		delete local_database_file;
		user_database = token;
		screen_msg(sformatf("Database file: %s\n\n", token.c_str()));
		db_file = token;
		output_msg(sformatf("   Input file: %s\n", in_file.c_str()));
		output_msg(sformatf("  Output file: %s\n", out_file.c_str()));
#ifdef NPP
		output_msg(sformatf("Using PHREEQC: version 3.9.1, compiled September 23, 2026\n"));
#endif
		output_msg(sformatf("Database file: %s\n\n", token.c_str()));
#ifdef NPP
		output_flush();
#endif
		/*
		*   local cleanup
		*/

		line = (char *) free_check_null(line);
		line_save = (char *) free_check_null(line_save);

		*db_cookie = new std::ifstream(db_file.c_str(), std::ios_base::in);
		*input_cookie = new std::ifstream(in_file.c_str(), std::ios_base::in);
	}
	catch (const PhreeqcStop&)
	{
		return get_input_errors();
	}
	return 0;
}
/* ---------------------------------------------------------------------- */
std::ifstream * Phreeqc::
open_input_stream(std::string query, std::string& default_name, std::ios_base::openmode mode, bool batch)
/* ---------------------------------------------------------------------- */
{
	std::string name;
	std::ifstream *new_stream;
	std::ostream * error_ostream_save = phrq_io->Get_error_ostream();

	for (;;)
	{
/*
 *   Get file name
 */
		name = default_name;
		if (!batch )
		{
			phrq_io->Set_error_ostream(&std::cerr);
			screen_msg(sformatf("%s\n", query.c_str()));
			if (default_name.size() > 0)
			{
				screen_msg(sformatf("Default: %s\n", default_name.c_str()));
			}
			std::getline(std::cin, name);
			if (name.size() == 0 && default_name.size() == 0)
			{
			    std::cerr << "No name defined." << std::endl;
				continue;
			}
			if (name.size() == 0)
			{
				name = default_name;
			}
		}
/*
 *   Open existing file to read
 */
		new_stream = new std::ifstream(name.c_str(), mode);
		if (new_stream == NULL || !new_stream->is_open())
		{
			phrq_io->Set_error_ostream(&std::cerr);
			error_string = sformatf( "\nERROR: Cannot open file, %s.\n", name.c_str());
			screen_msg(error_string);
#ifdef NPP
			error_msg(sformatf( "\nERROR: Cannot open file, %s.\n       Please check, and give the correct, full path + name.\n", name.c_str()), STOP);
			break;
#endif
			error_flush();
			batch = FALSE;
			continue;
		}
		break;
	}
	default_name = name;
	if (!batch )
	{
		phrq_io->Set_error_ostream(error_ostream_save);
	}
	return (new_stream);
}
/* ---------------------------------------------------------------------- */
std::ofstream * Phreeqc::
open_output_stream(std::string query, std::string& default_name, std::ios_base::openmode mode, bool batch)
/* ---------------------------------------------------------------------- */
{
	std::string name;
	std::ofstream *new_stream;
	std::ostream * error_ostream_save = phrq_io->Get_error_ostream();

	for (;;)
	{
/*
 *   Get file name
 */
		name = default_name;
		if (!batch )
		{
			phrq_io->Set_error_ostream(&std::cerr);
			screen_msg(sformatf("%s\n", query.c_str()));
			if (default_name[0] != '\0')
			{
				screen_msg(sformatf("Default: %s\n", default_name.c_str()));
			}
			std::getline(std::cin, name);
			if (name.size() == 0 && default_name.size() == 0)
			{
			    std::cerr << "No name defined." << std::endl;
			}
			if (name.size() == 0)
			{
				name = default_name;
			}
		}
/*
 *   Open existing file to read
 */
		new_stream = new std::ofstream(name.c_str(), mode);
		if (new_stream == NULL || !new_stream->is_open())
		{
			phrq_io->Set_error_ostream(&std::cerr);
			error_string = sformatf( "\nERROR: Cannot open file, %s.\n", name.c_str());
			screen_msg(error_string);
			error_flush();
			batch = FALSE;
			continue;
		}
		break;
	}
	default_name = name;
	if (!batch )
	{
		phrq_io->Set_error_ostream(error_ostream_save);
	}
	return (new_stream);
}
