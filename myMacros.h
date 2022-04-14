#pragma once
#define CHECK_RETURN_0(pCheck) {if(pCheck == NULL) return 0;} // 3 - AirportManager.c 169, Company.c 73, 77 

#define CHECK_RETURN_NULL(pCheck) if(pCheck == NULL) return NULL; // 1 - AirportManager.c - Line 72

#define CHECK_MSG_RETURN_0(pCheck,msg) if(pCheck == NULL){ printf(msg); return 0;} // 3 - AirportManager.c 154, 127, Company.c 130

#define CHECK_0_MSG_CLOSE_FILE(fp,value,msg) if(value == 0){printf("%s",msg); fclose(fp); return 0;} // 1 - AirportManager.c 173

#define CHECK_NULL__MSG_CLOSE_FILE(fp,value,msg) if(value == NULL){printf(msg); fclose(fp); return 0;} // 1 - Company.c 197

#define MSG_CLOSE_RETURN_0(fp, msg) {printf("%s", msg); fclose(fp); return 0;} // 3 - fileHelper.c 29, 49, 77