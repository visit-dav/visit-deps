/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef vtksys_Directory_hxx
#define vtksys_Directory_hxx

#include <vtksys/Configure.h>
#include <vtksys/Status.hxx>

#include <cstddef>
#include <string>

namespace vtksys {

class DirectoryInternals;

/** \class Directory
 * \brief Portable directory/filename traversal.
 *
 * Directory provides a portable way of finding the names of the files
 * in a system directory.
 *
 * Directory currently works with Windows and Unix operating systems.
 */
class vtksys_EXPORT Directory
{
public:
  Directory();
  Directory(Directory&& other);
  Directory(const Directory&) = delete;
  Directory& operator=(const Directory&) = delete;
  Directory& operator=(Directory&& other);
  bool operator==(const Directory&) = delete;
  ~Directory();

  /**
   * Load the specified directory and load the names of the files
   * in that directory.
   */
  Status Load(std::string const&, std::string* errorMessage = nullptr);

  /**
   * Return the number of files in the current directory.
   */
  unsigned long GetNumberOfFiles() const;

  /**
   * Return the number of files in the specified directory.
   * A higher performance static method.
   */
  static unsigned long GetNumberOfFilesInDirectory(
    const std::string&, std::string* errorMessage = nullptr);

  /**
   * Return the file at the given index, the indexing is 0 based
   */
  const char* GetFile(unsigned long) const;

  /**
   * Return the name of the file at the given 0-based index.
   */
  std::string const& GetFileName(std::size_t i) const;

  /**
   * Return the absolute path to the file at the given 0-based index.
   */
  std::string GetFilePath(std::size_t i) const;

  /**
   * Return whether the file at the given 0-based index is a directory.
   */
  bool FileIsDirectory(std::size_t i) const;

  /**
   * Return whether the file at the given 0-based index is a symlink.
   */
  bool FileIsSymlink(std::size_t i) const;

  /**
   * Return the path to Open'ed directory
   */
  const char* GetPath() const;

  /**
   * Clear the internal structure. Used internally at beginning of Load(...)
   * to clear the cache.
   */
  void Clear();

private:
  // Private implementation details.
  DirectoryInternals* Internal;
}; // End Class: Directory

} // namespace vtksys

#endif
