struct AsterReInfo {
    const char *start = nullptr;
    const char *end = nullptr;
    const char *pattern_start = nullptr;
};

class Solution {
public:
    bool isMatch(string s, string p) {
         vector<AsterReInfo> aster_stack;
 
      const char *cs = s.c_str();
      const char *cp = p.c_str();
      const char *prev_aster = nullptr;
 
      while (*cp) {
          const char *peek = cp + 1;
          if (*peek == '*') {
              if (prev_aster != peek) {
                      AsterReInfo Info;
                      Info.start = cs;
                      prev_aster = peek;
                      aster_stack.push_back(Info);
                  }
              if (*cs == 0 || *cs != *cp && *cp != '.') {
                  cp += 2;
                  if (!aster_stack.empty()) {
                      aster_stack.back().end= cs;
                      aster_stack.back().pattern_start = cp;
                  }
              } else {
                  
                  ++cs;
              }
          } else {
              if (*cs == 0 || *cs != *cp && *cp != '.') {
                  if (!aster_stack.empty() && aster_stack.back().end > aster_stack.back().start) {
                      --aster_stack.back().end;
                      cs = aster_stack.back().end;
                      cp = aster_stack.back().pattern_start;
                  } else if (!aster_stack.empty()) {
                      aster_stack.pop_back();
                  } else {
                      return false;
                  }
              } else {
                  ++cs;
                  ++cp;
              }
          }
      }
      return *cs == *cp;

    }
};

