#pragma once

#include "VehiclePawnWrapper.h"
#include "GameFramework/RotatingMovementComponent.h"
#include <memory>
#include "controllers/DroneCommon.hpp"
#include "PIPCamera.h"
#include "FlyingPawn.generated.h"

UCLASS()
class AIRSIM_API AFlyingPawn : public APawn
{
    GENERATED_BODY()

public:
    AFlyingPawn();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debugging")
    float RotatorFactor = 1.0f;

    void setRotorSpeed(int rotor_index, float radsPerSec);
    void initializeForBeginPlay();
    VehiclePawnWrapper* getVehiclePawnWrapper();

    virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation,
        FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
private: //methods
    void setupComponentReferences();
    void setStencilIDs();

private: //variables
         //Unreal components
    static constexpr size_t rotor_count = 4;
    UPROPERTY() APIPCamera* fpv_camera_left_;
    UPROPERTY() APIPCamera* fpv_camera_right_;
    UPROPERTY() URotatingMovementComponent* rotating_movements_[rotor_count];

    std::unique_ptr<VehiclePawnWrapper> wrapper_;
};
