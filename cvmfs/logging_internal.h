/**
 * This file is part of the CernVM File System.
 */

// Internal use, include only logging.h!

#ifndef CVMFS_LOGGING_INTERNAL_H_
#define CVMFS_LOGGING_INTERNAL_H_

#include <cstdarg>
#include <string>

enum LogFacilities {
  kLogDebug = 1,
  kLogStdout = 2,
  kLogStderr = 4,
  kLogSyslog = 8,
};

enum LogFlags {
  kLogNoLinebreak = 16,
  kLogShowSource = 32,
};

enum LogLevels {
  kLogLevel0 = 128,
  kLogVerbose = 256,
  kLogNormal = 512,
  kLogDiscrete = 1024,
  kLogNone = 2048,
};

enum LogSource {
  kLogCache = 1,
  kLogCatalog,
  kLogSql,
  kLogCvmfs,
  kLogHash,
  kLogDownload,
  kLogCompress,
  kLogQuota,
  kLogTalk,
  kLogMonitor,
  kLogLru,
  kLogFuse,
  kLogSignature,
  kLogPeers,
  kLogFsTraversal,
  kLogNfsMaps,
  kLogPublish,
  kLogSpooler,
};

const int kLogVerboseMsg = kLogStdout | kLogShowSource | kLogVerbose;

void SetLogSyslogLevel(const int level);
void SetLogSyslogPrefix(const std::string &prefix);
void SetLogVerbosity(const LogLevels min_level);

#ifdef DEBUGMSG
void SetLogDebugFile(const std::string &filename);
std::string GetLogDebugFile();
#else
#define SetLogDebugFile(filename) ((void)0)
#define GetLogDebugFile() (std::string(""))
#endif

void SetAltLogFunc(void (*fn)(const LogSource source, const int mask,
                              const char *msg));

#endif  // CVMFS_LOGGING_INTERNAL_H_
