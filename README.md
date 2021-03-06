# SimpleSyncService [![Build Status](https://travis-ci.org/kattrali/SimpleSyncService.png?branch=master)](https://travis-ci.org/kattrali/SimpleSyncService)

A simple, customizable service for updating Core Data models. It uses [ObjectiveRecord](https://github.com/mneorr/ObjectiveRecord) for mapping data in dictionary format to a Core Data entity's properties.


## Usage

### Manual

After fetching new data with which to update and insert new model instances, invoke the synchronization service to reconcile the new data with a Core Data entity.


    #import <SimpleSyncService/SimpleSyncService.h>
    
    // (Perform some fetching task, format data as an array
    // of dictionaries...)
    
    [SimpleSyncService synchronizeData:arrayOfUpdatedModelData
                        withEntityName:modelEntityName
                             inContext:managedObjectContext
                   withIdentifierNamed:@"remoteID"];


The identifier property is used to determine whether an existing record should be updated or a new record should be inserted.

### Automatic

Format data fetching tasks as synchronization service adapters which are invoked on a background queue at customizable intervals. The basic flow is as follows:

1. Subclass `DMMSyncServiceAdapter` and write your fetching code in `fetchDataWithCompletion:`, remembering to invoke the `SyncCompletionBlock` when done fetching and formatting data.

2. Initialize your adapters with `initWithInterval:entityName:modelIDKey:` using the interval at which they should be run and the entity name of the model to upate. The `modelIDKey` is used to determine whether new data should update an existing record or be inserted as a new one.

3. Create a new `SimpleSyncService` instance with your adapters and preferred operation queue using `initWithAdapters:useQueue:`

4. Start the service with `start`

5. Stop the service at any time using `stop`

An example of this flow is included in the sample project in this repository.


## Installation

Include `pod 'SimpleSyncService'` in your [Podfile](http://cocoapods.org)


## Contributing

Contributions welcome, SimpleSyncService is testing using [Kiwi](https://github.com/allending/Kiwi).
