//
//  Person.h
//  SampleProject
//
//  Created by Girgis on 08/01/14.
//  Copyright (c) 2014 Delisa Mason. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Cat;

@interface Person : NSManagedObject

@property (nonatomic, retain) NSString * email;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * numberOfCats;
@property (nonatomic, retain) NSSet *cats;
@end

@interface Person (CoreDataGeneratedAccessors)

- (void)addCatsObject:(Cat *)value;
- (void)removeCatsObject:(Cat *)value;
- (void)addCats:(NSSet *)values;
- (void)removeCats:(NSSet *)values;

@end
