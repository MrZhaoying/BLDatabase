//
//  BLDatabase.h
//  BLAlimeiDatabase
//
//  Created by alibaba on 15/5/11.
//  Copyright (c) 2015年 wxw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLDatabaseConnection.h"

typedef void(^BLMigrationBlock)(BLDatabaseConnection *databaseConnection, NSUInteger oldSchemaVersion);

@interface BLDatabase : NSObject

@property (nonatomic, copy, readonly) NSString *databasePath;
@property (nonatomic, strong, readonly) NSHashTable *connections;

+ (instancetype)memoryDatabase;

+ (instancetype)memoryDatabaseWithUniqueName:(NSString *)uniqueName;

+ (instancetype)defaultDatabase;

+ (instancetype)databaseWithName:(NSString *)name;

+ (instancetype)databaseWithPath:(NSString *)path;

- (void)setSchemaVersion:(NSUInteger)version
      withMigrationBlock:(BLMigrationBlock)block;

// type is BLPrivateQueueDatabaseConnectionType
- (BLDatabaseConnection *)newConnection;

- (BLDatabaseConnection *)newConnectionWithType:(BLDatabaseConnectionType)type;

@end
