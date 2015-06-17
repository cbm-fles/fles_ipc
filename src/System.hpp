// Copyright 2013 Jan de Cuveland <cmail@cuveland.de>
/// \file
/// \brief Defines utility functions in the fles::system namespace.

#include <string>

namespace fles
{
/// Namespace for system-related utilty functions.
namespace system
{
/**
 * \brief Textual description of system error messages.
 *
 * This is a thin C++ wrapper around strerror_r(), which looks up the error
 * message string corresponding to an error number.
 *
 * @param errnum Error number
 * @return message string
 */
std::string stringerror(int errnum);

/**
 * \brief Retrieve current user name.
 *
 * This is a thin C++ wrapper around getpwuid_r(), which obtains information
 * from the system password database.
 *
 * @return user name corresponding to current process
 */
std::string current_username();

/**
 * \brief Retrieve current host name.
 *
 * This is a thin C++ wrapper around gethostname(), which gets the name of the
 * current host.
 *
 * @return current host name
 */
std::string current_hostname();

/**
 * \brief Retrieve current domain name.
 *
 * This is a thin C++ wrapper around getdomainname(), which gets the standard
 * NIS domain name for the current host.
 *
 * @return current domain name
 */
std::string current_domainname();

} // namespace system {
} // namespace fles {
