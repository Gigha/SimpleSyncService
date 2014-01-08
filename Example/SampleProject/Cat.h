//
//  Cat.h
//  SampleProject
//
//  Created by Girgis on 08/01/14.
//  Copyright (c) 2014 Delisa Mason. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Person;

@interface Cat : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * specie;
@property (nonatomic, retain) Person *owner;

@end
